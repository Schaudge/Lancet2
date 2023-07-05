#include "lancet/caller/variant_call.h"

#include <algorithm>
#include <cmath>

#include "absl/container/btree_set.h"
#include "absl/strings/str_cat.h"
#include "absl/strings/str_join.h"
#include "lancet/base/compute_stats.h"
#include "lancet/base/hash.h"
#include "lancet/hts/fisher_exact.h"
#include "spdlog/fmt/fmt.h"

namespace {

[[nodiscard]] inline auto HashRawVariant(const lancet::caller::RawVariant *var) -> u64 {
  return HashStr64(fmt::format("{},{},{},{},{},{}", var->mChromName, var->mGenomeStart1, var->mRefAllele,
                               var->mAltAllele, var->mAlleleLength, static_cast<i8>(var->mType)));
}

}  // namespace

namespace lancet::caller {

VariantCall::VariantCall(const RawVariant *var, Supports &&supprts, Samples samps, const Params &prms, const usize klen)
    : mVariantId(HashRawVariant(var)), mChromIndex(var->mChromIndex), mStartPos1(var->mGenomeStart1),
      mTotalSampleCov(0), mChromName(var->mChromName), mRefAllele(var->mRefAllele), mAltAllele(var->mAltAllele),
      mVarLength(var->mAlleleLength), mSiteQuality(0), mCategory(var->mType) {
  PerSampleEvidence per_sample_evidence;
  per_sample_evidence.reserve(supprts.size());

  for (const auto &sinfo : samps) {
    auto itr = supprts.find(sinfo.SampleName());
    if (itr == supprts.end()) {
      per_sample_evidence.emplace(sinfo, std::make_unique<VariantSupport>());
      continue;
    }

    auto handle = supprts.extract(itr);
    per_sample_evidence.emplace(sinfo, std::move(handle.mapped()));
  }

  mFormatFields.reserve(samps.size() + 1);
  mFormatFields.emplace_back("GT:AD:ADF:ADR:DP:AAF:SBS:SSC:FT:GQ:PL");

  // Strand Bias if more than 10 times likely to see ALT on one strand over the other
  static constexpr u32 MAX_ALLOWED_STRAND_BIAS = 10;

  static const auto is_normal = [](const auto &sinfo) -> bool { return sinfo.TagKind() == cbdg::Label::NORMAL; };
  const auto germline_mode = std::ranges::all_of(samps, is_normal);

  bool alt_seen_in_normal = false;
  bool alt_seen_in_tumor = false;
  std::vector<std::string> current_filters;
  absl::btree_set<std::string> variant_site_filters;
  const auto is_str = var->mStrResult.mFoundStr;

  for (const auto &sinfo : samps) {
    const auto &evidence = per_sample_evidence.at(sinfo.SampleName());

    const auto phred_likelihoods = evidence->ComputePLs();
    const auto [ref_hom_pl, het_alt_pl, alt_hom_pl] = phred_likelihoods;
    const auto [smallest_index, second_smallest_index] = FirstAndSecondSmallestIndices(phred_likelihoods);

    const auto genotype = POSSIBLE_GENOTYPES.at(smallest_index);
    const auto genotype_quality = static_cast<u32>(phred_likelihoods.at(second_smallest_index));

    const auto alt_allele_frequency = evidence->AltFrequency();
    const auto alt_strand_bias_score = evidence->AltStrandBiasScore();
    const auto fisher_score = SomaticScore(sinfo, per_sample_evidence);
    const auto somatic_score = fisher_score > hts::MAX_PHRED_SCORE ? prms.mMinSomaticScore : fisher_score;

    mSiteQuality = std::max(mSiteQuality, germline_mode ? static_cast<u32>(ref_hom_pl) : somatic_score);
    mTotalSampleCov += evidence->TotalSampleCov();
    current_filters.clear();

    if (sinfo.TagKind() == cbdg::Label::NORMAL) {
      // NOLINTBEGIN(readability-braces-around-statements)
      if (evidence->TotalSampleCov() < prms.mMinNmlCov) current_filters.emplace_back("LowNmlCov");
      if (!germline_mode && alt_allele_frequency > prms.mMaxNmlVaf) current_filters.emplace_back("HighNmlVaf");
      if (germline_mode && alt_strand_bias_score > MAX_ALLOWED_STRAND_BIAS) current_filters.emplace_back("StrandBias");
      // NOLINTEND(readability-braces-around-statements)
    }

    if (sinfo.TagKind() == cbdg::Label::TUMOR) {
      // NOLINTBEGIN(readability-braces-around-statements)
      if (evidence->TotalSampleCov() < prms.mMinTmrCov) current_filters.emplace_back("LowTmrCov");
      if (alt_strand_bias_score > MAX_ALLOWED_STRAND_BIAS) current_filters.emplace_back("StrandBias");
      if (fisher_score < prms.mMinSomaticScore) current_filters.emplace_back("LowSomaticScore");
      // NOLINTEND(readability-braces-around-statements)
    }

    std::ranges::sort(current_filters);
    variant_site_filters.insert(current_filters.cbegin(), current_filters.cend());
    const auto sample_ft_field = current_filters.empty() ? "PASS" : absl::StrJoin(current_filters, ";");

    // NOLINTBEGIN(readability-braces-around-statements)
    if (genotype != REF_HOM && sinfo.TagKind() == cbdg::Label::NORMAL) alt_seen_in_normal = true;
    if (genotype != REF_HOM && sinfo.TagKind() == cbdg::Label::TUMOR) alt_seen_in_tumor = true;
    // NOLINTEND(readability-braces-around-statements)

    mFormatFields.emplace_back(
        // GT:AD:ADF:ADR:DP:VAF:SBS:SSC:FT:GQ:PL
        fmt::format("{}:{},{}:{},{}:{},{}:{}:{:.4f}:{}:{}:{}:{}:{},{},{}", genotype, evidence->TotalRefCov(),
                    evidence->TotalAltCov(), evidence->RefFwdCount(), evidence->AltFwdCount(), evidence->RefRevCount(),
                    evidence->AltRevCount(), evidence->TotalSampleCov(), alt_allele_frequency, alt_strand_bias_score,
                    somatic_score, sample_ft_field, genotype_quality, ref_hom_pl, het_alt_pl, alt_hom_pl));
  }

  mFilterField = variant_site_filters.empty() ? "PASS" : absl::StrJoin(variant_site_filters, ";");
  mState = alt_seen_in_normal && alt_seen_in_tumor ? RawVariant::State::SHARED
           : alt_seen_in_normal                    ? RawVariant::State::NORMAL
           : alt_seen_in_tumor                     ? RawVariant::State::TUMOR
                                                   : RawVariant::State::NONE;

  using namespace std::string_view_literals;
  const auto vstate = mState == RawVariant::State::SHARED   ? "SHARED"sv
                      : mState == RawVariant::State::NORMAL ? "NORMAL"sv
                      : mState == RawVariant::State::TUMOR  ? "TUMOR"sv
                                                            : "NONE"sv;

  const auto vcategory = mCategory == RawVariant::Type::SNV   ? "SNV"sv
                         : mCategory == RawVariant::Type::INS ? "INS"sv
                         : mCategory == RawVariant::Type::DEL ? "DEL"sv
                         : mCategory == RawVariant::Type::MNP ? "MNP"sv
                                                              : "REF"sv;

  const auto str_info = is_str ? fmt::format(";STR={}{}", var->mStrResult.mStrLen, var->mStrResult.mStrMotif) : "";
  mInfoField = fmt::format("{};CATEGORY={};LEN={};KMERSIZE={}{}", vstate, vcategory, mVarLength, klen, str_info);
}

auto VariantCall::AsVcfRecord() const -> std::string {
  auto vcf_record = fmt::format("{}\t{}\t.\t{}\t{}\t{}\t{}\t{}\t{}", mChromName, mStartPos1, mRefAllele, mAltAllele,
                                mSiteQuality, mFilterField, mInfoField, absl::StrJoin(mFormatFields, "\t"));

  // No newline. caller of this method will add new line if needed
  return vcf_record;
}

auto VariantCall::SomaticScore(const core::SampleInfo &curr, const PerSampleEvidence &supports) -> u32 {
  // NOLINTNEXTLINE(readability-braces-around-statements)
  if (curr.TagKind() != cbdg::Label::TUMOR) return 0;

  u32 max_nml_alt_cnt = 0;
  u32 current_tmr_alt = 0;
  u32 current_tmr_ref = 0;
  OnlineStats nml_alts;
  OnlineStats nml_refs;

  for (const auto &[sample_info, evidence] : supports) {
    // Ignore other tumor samples even if present
    if (sample_info.SampleName() == curr.SampleName()) {
      current_tmr_alt = evidence->TotalAltCov();
      current_tmr_ref = evidence->TotalRefCov();
      continue;
    }

    if (sample_info.TagKind() == cbdg::Label::NORMAL) {
      nml_alts.Add(evidence->TotalAltCov());
      nml_refs.Add(evidence->TotalRefCov());
      max_nml_alt_cnt = std::max(max_nml_alt_cnt, static_cast<u32>(evidence->TotalAltCov()));
    }
  }

  // NOLINTNEXTLINE(readability-braces-around-statements)
  if (max_nml_alt_cnt == 0 && current_tmr_alt > 0) return static_cast<u32>(hts::MAX_PHRED_SCORE) + 1;

  const auto cnt_tmr_alt = static_cast<int>(current_tmr_alt);
  const auto cnt_tmr_ref = static_cast<int>(current_tmr_ref);
  const auto avg_nml_alt = static_cast<int>(std::round(nml_alts.Mean()));
  const auto avg_nml_ref = static_cast<int>(std::round(nml_refs.Mean()));

  using Row = hts::FisherExact::Row;
  const auto tmr_counts = Row{cnt_tmr_alt, cnt_tmr_ref};
  const auto nml_counts = Row{avg_nml_alt, avg_nml_ref};
  const auto result = hts::FisherExact::Test({tmr_counts, nml_counts});
  return static_cast<u32>(hts::ErrorProbToPhred(result.mDiffProb));
}

auto VariantCall::FirstAndSecondSmallestIndices(const std::array<int, 3> &pls) -> std::array<usize, 2> {
  const auto *min_itr = std::ranges::min_element(pls);
  const auto smallest_idx = static_cast<usize>(std::distance(pls.cbegin(), min_itr));

  const auto second_min_comparator = [&min_itr](const int lhs, const int rhs) -> bool {
    return (lhs == *min_itr) ? false : (rhs == *min_itr) ? true : lhs < rhs;
  };

  const auto *second_itr = std::ranges::min_element(pls, second_min_comparator);
  const auto second_smallest_idx = static_cast<usize>(std::distance(pls.cbegin(), second_itr));

  return {smallest_idx, second_smallest_idx};
}

}  // namespace lancet::caller
