
<a name="v2.8.6"></a>
## [v2.8.6](https://github.com/nygenome/Lancet2/compare/v2.9.5...v2.8.6) (0001-01-01)


<a name="v2.9.5"></a>
## [v2.9.5](https://github.com/nygenome/Lancet2/compare/v2.8.5...v2.9.5) (2025-02-06)

### Bug Fixes

* remove lowscore filter
* use only stm repo data directory

### Maintenance/Refactoring

* Bump version to v2.9.5
* update dependencies
* add somtic model and filter script to docker image
* add somtic model and filter script to docker image
* minor fix to prep_stm_viz.sh
* temp remove for lfs tracking
* temp clean git index
* update ide config files
* update dependencies
* update default version string
* update ide files for new dev vm
* Update Dockerfile
* resolve multiple clang-tidy warnings
* resolve multiple clang-tidy warnings

### New Features

* use 10 and 13 cutoffs & always write non pass variants
* add script to prep all necessary files for STM viz
* bundle ml model with repo
* bundle ml model with repo
* update filter script to use 10_15 cutoffs
* bundle ml model with repo
* bundle ml model with repo
* increase max window coverage per sample to 1000


<a name="v2.8.5"></a>
## [v2.8.5](https://github.com/nygenome/Lancet2/compare/v2.8.4...v2.8.5) (2024-05-10)

### Maintenance/Refactoring

* Bump version to v2.8.5
* update cmake version and use gcc14 for docker build
* update dependencies
* update Dockerfile
* update dependencies
* add pyproject toml details

### New Features

* update python deps and filter_variants script to use latest model


<a name="v2.8.4"></a>
## [v2.8.4](https://github.com/nygenome/Lancet2/compare/v2.8.3...v2.8.4) (2024-03-04)

### Bug Fixes

* Handle case when no reads in window
* handle potential math domain error
* use only class without score
* resolve bug in pysam api usage and add some log msgs

### Maintenance/Refactoring

* Bump version to v2.8.4
* temporarily remove score cutoff
* update conda env deps

### New Features

* use only hq reads to genotype variants
* update ml model features in apply script
* set qual >=5 i.e. ~70% probability of somatic as cutoff
* only output PASS variants to stdout vcf
* add script to apply somatic ML filtering model


<a name="v2.8.3"></a>
## [v2.8.3](https://github.com/nygenome/Lancet2/compare/v2.8.2...v2.8.3) (2024-02-25)

### Bug Fixes

* compute min and max before changing for mad
* resolve typo

### Maintenance/Refactoring

* Bump version to v2.8.3
* allow logging htslib errors
* make minor imports
* update cmake version in dockerfile
* update deps & remove extra hash deps

### New Features

* expand str info into flag, unit length and motif
* expand stats by adding min, max and median abs. deviation
* remove vcf filters & post call filtering to incorporate ML filtering
* use low qual reads for GTing & vcf stats but not for graph


<a name="v2.8.2"></a>
## [v2.8.2](https://github.com/nygenome/Lancet2/compare/v2.8.1...v2.8.2) (2023-11-30)

### Maintenance/Refactoring

* Bump version to v2.8.2
* update dockerfile
* update dependencies and remove v prefix

### New Features

* use same read filters for tumor and normal


<a name="v2.8.1"></a>
## [v2.8.1](https://github.com/nygenome/Lancet2/compare/v2.8.0...v2.8.1) (2023-11-28)

### Bug Fixes

* resolve typo in version inc
* update vcf header for clarity
* remove rounding in phred

### Maintenance/Refactoring

* Bump version to v2.8.1


<a name="v2.8.0"></a>
## [v2.8.0](https://github.com/nygenome/Lancet2/compare/v2.7.0...v2.8.0) (2023-11-28)

### Maintenance/Refactoring

* Bump version to v2.8.0

### New Features

* Add window level FMT fields and convert Int to Float


<a name="v2.7.0"></a>
## [v2.7.0](https://github.com/nygenome/Lancet2/compare/v2.6.0...v2.7.0) (2023-11-22)

### Bug Fixes

* make downsampling more predictable

### Maintenance/Refactoring

* Bump version to v2.7.0
* update deps


<a name="v2.6.0"></a>
## [v2.6.0](https://github.com/nygenome/Lancet2/compare/v2.5.0...v2.6.0) (2023-10-24)

### Bug Fixes

* ensure min chunk length for fuzzy matching
* use 90% of chunk length for fuzzy match cutoff
* count longer indels better with using min of var and read len

### Maintenance/Refactoring

* Bump version to v2.6.0
* remove extra commands in version extract


<a name="v2.5.0"></a>
## [v2.5.0](https://github.com/nygenome/Lancet2/compare/v2.4.0...v2.5.0) (2023-10-23)

### Bug Fixes

* reserve vector length before use
* return untouched ref and qry
* resolve typo in logic

### Maintenance/Refactoring

* Bump version to v2.5.0
* ensure we don't go over max kmer len
* update deps

### New Features

* add fuzzy matching for genotyping long indels


<a name="v2.4.0"></a>
## [v2.4.0](https://github.com/nygenome/Lancet2/compare/v2.3.0...v2.4.0) (2023-10-19)

### Bug Fixes

* update vcf header text
* simplify and remove max normal filter
* resolve typo in if statement
* reduce flank to 3 exact match
* remove str specific filter
* check for non gap alignment of flanks instead of match
* reduce AS/XS diff to 1 percent
* reduce AS/XS diff to 5 percent
* reduce AS/XS diff to 10 percent
* increase min difference between AS and XS
* use same value for ends and flank match
* revert back remove short link
* reduce min uniq seq len before trim links
* resolve bug which fails to compile with latest btree
* resolve bug in pre loop value
* increment kmer len by cli step len value
* re-run docs action on change in config

### Maintenance/Refactoring

* Bump version to v2.4.0
* rename function
* set ends non gap len to 11
* revert back run config
* update deps
* rename actions config
* remove and re-add yml to debug
* Update github-action-deploy.yml
* add styles.module.css
* Add back index.module.css
* Add docker info to README
* auto-use git tag version

### New Features

* genotype insertions where read is not fully contained
* change default kmer min, max and step
* add indel specific fisher score threshold
* add strict normal vaf filter for STRs
* double min odds ratio for str variants
* use 1% nml vaf threshold in STR
* add AS/XS filter with 10% difference threshold
* add flank match check to improve precision
* add back short link removal with very lenient params
* add back AS-XS, XT/XA tag read filters
* add kmer step size cli flag

### Reverts

* feat: add back AS-XS, XT/XA tag read filters

### Pull Requests

* Merge pull request [#8](https://github.com/nygenome/Lancet2/issues/8) from nygenome/web_docs


<a name="v2.3.0"></a>
## [v2.3.0](https://github.com/nygenome/Lancet2/compare/v2.2.0...v2.3.0) (2023-08-30)

### Maintenance/Refactoring

* Bump version to v2.3.0

### Performance Improvements

* optimize graph build by removing cord, turn off secure mimalloc


<a name="v2.2.0"></a>
## [v2.2.0](https://github.com/nygenome/Lancet2/compare/v2.1.0...v2.2.0) (2023-08-30)

### Bug Fixes

* reduce default min tumor cov filter

### Maintenance/Refactoring

* Bump version to v2.2.0
* remove redundant flag from run config
* remove runtime stats option
* comment out profiling code from release build
* update deps
* use 10mb non gap window for testing
* update dependencies
* update dependencies and docker file
* update deps and dockerfile
* add explicit preset option in genotyper, defaulting to sr
* use max per sample coverage of 500
* rename image name
* update cmake project version
* change cloud build project
* remove redundant cmake configure
* always use commit group type

### Performance Improvements

* optimize queue operations
* throttle counter and reduce default window & overlap


<a name="v2.1.0"></a>
## [v2.1.0](https://github.com/nygenome/Lancet2/compare/v2.0.0.rc2-main-a055ecdecf...v2.1.0) (2023-07-06)

### Bug Fixes

* use VCFv4.3 and skip adding MQ0 reads

### Maintenance/Refactoring

* Bump version to v2.1.0


<a name="v2.0.0.rc2-main-a055ecdecf"></a>
## [v2.0.0.rc2-main-a055ecdecf](https://github.com/nygenome/Lancet2/compare/v2.0.0.rc1...v2.0.0.rc2-main-a055ecdecf) (2023-06-25)

### Bug Fixes

* resolve undercounting ref for long alleles
* resolve score overflow issue
* resolve typo in while check
* count end gaps and handle it correctly in var ranges
* use more conservative assembly to ref scoring
* create parent path of output vcf if needed
* revert back to v1.14 libdeflate because latest version breaks build
* resolve typo in spdlog usage
* skip regions which have 0 or more than 3 tokens
* include cmake install line
* use debian as default base image
* use relative path to inject right require on build Former-commit-id: 96128bd509124cbd0573dac47a29eacbfe8acb9c Former-commit-id: 40c9b35f7aa984b7b79c6614064cd03ce1aaec5d Former-commit-id: 74cf99ef548050f677de5cce6da1d9ebb9bea6a6
* change config to include static assets Former-commit-id: 468c8c6669da39dcc3a94671db7547a03609a238 Former-commit-id: c65a78edf57ae926af2bee2ee65f13913b8a32a0 Former-commit-id: e8e292b5af811cd57aa7e2f4536244f10113ab1d
* use public api to refer to transcipt member variable Former-commit-id: c0a546e87d8b7b105b4a151ca36e001c6b21f0d0 Former-commit-id: d51fb61953e975c2ed71a5f9c3d031346e6bed41 Former-commit-id: 9cc4265b74796c1f7f3eae08e397890ed611b518
* use node fill colors consistent with v1 Former-commit-id: d6e674c494ec0f1002fd64c3b2c96696c23354f6 Former-commit-id: 1691140cbaf41b10c3649af78fa0b458945c0d3b Former-commit-id: 073c09532824d6984acea58824197e7ecc65216d
* alternate index file missing file extension dot Former-commit-id: dbe5d677498947db73be612a514fffcd7a7ff464 Former-commit-id: 248c5500dbd3141600d610f207cf8099f30f112d Former-commit-id: 240652b1a022c224731387819a7ff0d58a95ee48

### Maintenance/Refactoring

* fix typo in dockerfile
* add dockerfile fi
* update dependencies and build tasks
* update local build settings & gitignore
* update CMP0135 policy
* update CMP0135 policy
* update deps
* keep only gcc build Former-commit-id: facbfe77ae435592f8cd0e029e00b8349a2ff446 Former-commit-id: 6d01d6a27eb1c7fdf65dfe33bdbae974bf4d810b Former-commit-id: 4dcb3a240bde0daf58d98d139bd0fb3c9263fe7e
* update graphviz image
* remove ghcr from build to prevent push 403 errors Former-commit-id: 4f83100db7dcea3e5f953573c1ce498831bdc3ed Former-commit-id: a8fd94a3e496a1bc24fd319466b4501e054a38fe Former-commit-id: fae57a5d155e73bc566face970b44d53e6f0cefa
* update readme Former-commit-id: a38e811ade0e6d800a06ec705c295db973eb7150 Former-commit-id: f4f01d634fd6c48fc75cfae8be8dbd5b74ff54b0 Former-commit-id: cc929dc6fc954ca834fa14f32a1ff97cad9b0edf
* Update docs Former-commit-id: a464948922765af128e9f62f302aa3ce5271adf1 Former-commit-id: 80f708b507a345305a5c006b4d6f6514e1c8f65a Former-commit-id: a1302cd2c95236f53c7a5162c0a9caea9d52ea37
* Update docs Former-commit-id: 33f97e8b6a9a54a6fb732dd5462788f36640e7af Former-commit-id: ce5d5a2c9756fe8909d914c61d5ec24f2f0b71a3 Former-commit-id: 93ea17c7d3a5d9ba273c582b2752239a88a05dbb
* Update docs Former-commit-id: 3cc3f6490331cffff8c7c9f526218727364bde10 Former-commit-id: e565f6d9889b716cdd122e3435f7ca633541d134 Former-commit-id: 9d0c32e191be8fef0af955acd649b40e5c2348b3
* Update docs Former-commit-id: 6dc05d640cce51eaecf630749372c868cff5a911 Former-commit-id: 5d4a4b1c7645a3b89a758686ba2af59601dfdcd5 Former-commit-id: abd3d761420e5e6d0c004f5ed366c5969e14f901
* Update docs Former-commit-id: 37d33bcf5ff3165e1700e047bce73f8d8b2f3091 Former-commit-id: 33dbeccd68ef8e375f7fa2ae59c2a20c6f964490 Former-commit-id: 9735acbb78ea328068b708be28cd27cc49caa9da
* Update docs Former-commit-id: 9cf6883ed91fc6954319b9eef2369a2c3e703e65 Former-commit-id: 3a1e40f66fd9a3145632940761ae3c43dc866dfb Former-commit-id: 6a4a699221bc73671d7df2a8607cda6e9fd32cdc
* Update docs Former-commit-id: 1c5ca07cc1317fba1cc7afef87f1c07df4489045 Former-commit-id: d47e8ce4a3cbf063556104d481c6438b5e529d29 Former-commit-id: ce29c3f75a97617c61c41edbd33902d1606b7d7c
* Update docs Former-commit-id: b4f36182263f776aad6007d681da1a7596691a53 Former-commit-id: f7dbf5412c23e2d7f45740bb8300a5a1acdf5c38 Former-commit-id: bfa255ddaf79995a1d126cd011697cdf12cf003e
* Update docs Former-commit-id: 6ea9c8203426e6a344a48a9b1074774b58d19599 Former-commit-id: 20fcca4ef3717bfd7c4fb8852e95fe57e91eeeae Former-commit-id: 5446c5fec6669b4d92ed9213a07ba36dd4daf848
* Update docs Former-commit-id: 8a587117fbdf8b5dc91064a68efa5b7cae7ae004 Former-commit-id: 25255c194fe0cd248490ddff72db792a54f779e5 Former-commit-id: 1b66b168849637c3ddd7037773a69581379024dc
* Update docs Former-commit-id: 6b0b2d9effb71d8394dc41f836916af853070766 Former-commit-id: 54e99f29258b47b3cef70fa7d9aeef39ddd54038 Former-commit-id: 5ede0eda990754840c590afcac290ba85a26ccab
* Update docs Former-commit-id: eed98b81155ae60737996e184912d0de6403461b Former-commit-id: 30d5b3e2a4c763040dd3323137f3186286f790c1 Former-commit-id: 26c3254e281e5e1ff71d857420bf3ed0af15db46
* Update docs Former-commit-id: c31b9397df30264ec156691465636bba3e0aef05 Former-commit-id: a02f16c46d0020d6b1ed5ac653c8deedba3d8016 Former-commit-id: f0cf954c65c0ece715a28c54e54b283acb2f02c0
* Update docs Former-commit-id: 061e979f05de97e1c96d705b20b9681613b61027 Former-commit-id: c68d6163558c27a60906615c6a5ff33afcc3b781 Former-commit-id: 3d14e32fcf3e83950d1e5534df9ee3a45d828537
* Update docs Former-commit-id: 942afe8a454aef8a1364093c8364a8e597ad182f Former-commit-id: a1c6cdb20ad154faeaac9cc07ec5bf583dd9ed75 Former-commit-id: 50b0f7c062d0f7306833d460426474e9904ad70b
* update docs Former-commit-id: 4b7c302b80e12dda4bb8a320a834fa868b05ee40 Former-commit-id: 7190b770e35badc7730974caf37c5d764147ff2d Former-commit-id: b23a08bb6d9ace976ac42d4c1d89ce600d0a3eb7
* update docs config Former-commit-id: e19ab764bc32800f9466372ca28a3fbbc06c5abe Former-commit-id: c205583da1f63b476e552eff0bb74747fb54b9c9 Former-commit-id: 9614b69eac2c6b1f9a1694cd651c308601ee7116
* use permalinks Former-commit-id: c1e9356207ef3f2e95e21fea5a9fc8df11baf9a5 Former-commit-id: fc3ffc309b50c02fa62c01ab61825da09eb2841f Former-commit-id: ae0b1c6e0a42011f10f92deaa8750142472f2fcd
* update visualization section in docs Former-commit-id: 0dda6c83b86b3c80a494de76df1f164a7d76ba5c Former-commit-id: d97e23e1f3e4e8ef7d493577cdebf959d1dff559 Former-commit-id: 866a20e845164ff7cbcb0a6564cf1ba134769e81
* use 0 component for raw graph Former-commit-id: e055d13eb84efec2c8d5693b1f0c43b3ad8dec2a Former-commit-id: c8c60bb1bdc3fd95b610cdfac6dc08680935a6a8 Former-commit-id: 5c8977e2ba9dc06547219b7469213f9084f53172
* also build dot file before low cov removal Former-commit-id: f1f1e775e5949f46e2ac7c80c3f19d6c42017303 Former-commit-id: ab3449a1a319a9f2db05452f14abff3ddf833079 Former-commit-id: 490be6ee4bafe791ad62233b2fd348ad0cf9d953
* ensure non ref alt allele Former-commit-id: e68f2bb6e9c38b1c7926a9781f17ee7988e48c79 Former-commit-id: bdcba126ca1593b7fdcd9673a9ceffe83cac3558 Former-commit-id: 62098deb02f19bae5a4488a181d4b3a7b9df6b26

### New Features

* add rname hash to prevent double counting
* add median
* Fix scoring to call variants longer than read length

### Reverts

* Updating website


<a name="v2.0.0.rc1"></a>
## v2.0.0.rc1 (2022-08-10)

### Bug Fixes

* use separate kmer sizes for ref and alt
* resolve typo which removes all normal reads
* use uniq kmer for path seq
* use bq pass only for low quality singleton normal alt snvs
* check if all low qual bases in normal, skip left/right flank for indels
* resolve logic for when no flank is needede
* resolve logic error in if block
* use bq filter for normal only when one low qual SNV alt base found
* use bq filter for snvs and tumor reads
* use bq filter only for snvs
* use bq filter for all single allele haplotypes
* 0 based ref window excludes end, so remove +1
* use right ref and qry indexes after trimming alignment ([#3](https://github.com/nygenome/Lancet2/issues/3))
* only check high qual snv bases in tumor
* skip adding to kmer coverage for snvs in low qual bases
* add header lines for base qual filters
* remove redundant param
* remove overlap check for read pairs
* always use overlapping reads to increase recall, skip adding empty readInfos
* use right binary path
* go back to full left flank to undo regression in perf
* use small fixed left flank to improve recall
* remove isSomatic ? 0 blocks to fix logic
* use index (0-based) instead of pos (1-based) to pick the spanning node
* break when best path is confirmed
* dont skip nodes in component in remove tips
* swap data with temp to force release of hash table memory
* use vector and .at() to remove undefined behavior
* use padded region end to build windows
* handle unmapped alignments where read and/or mate is unmapped
* use flush ref window instead of index
* handle all window exceptions to prevent deadlock in main thread
* skip on invalid iterator before checking for node ptr
* adjust anchor start on trimming, ensure non bases are not added
* skip early to prevent operating on invalid nodes
* skip returning erased/rehashed node ptrs
* increment index to flush even when no variants are flushed
* allow for merged data source/sink in checks
* trim end gaps in alignments if they exist
* use right positons to point to mismatches (0-based aln start)
* remove -march=native to allow cross compatability
* remove alpine and use ubuntu/debian based builds to fix SIGILLs
* add mutex to log calls to prevent interleaved messages
* move log message before removing
* return from microassembler thread on error
* use shared_ptr without going out of scope
* use right syntax to get value
* use right syntax to get value
* impose strict weak ordering in sort
* add option to skip truncated reference windows

### Maintenance/Refactoring

* use unique path kmer
* use bioinformatics link Former-commit-id: 1fc7c9831a78323c1f348f1a263432a43389e49e Former-commit-id: 2043ca4c05c59bbb57b13ad1dc82b1b53eaf7acc Former-commit-id: 434ccc77009e54405fb7ec14c04d0053dd91f317
* skip low qual normal snvs
* use raw cov for normal always
* change normal read filters
* minor refactoring and edits
* use old merging logic for node labels
* always use bq pass filter for both tmr and nml read snvs
* use overlapping reads
* use contained reads
* make method static
* add new base coverage class
* use non inlined import
* minor edits and refactoring
* add helper canonical hash helper
* replace variants with higher fet score
* remove use contained flag
* remove alt qual from vcf
* reorder loop for perf
* only filter tmr alt quals
* minor edits to fix clang tidy warnings, log trace on alignment erorr
* remove float specifier
* bump to release candidate 1
* use caught exception directly
* add cmake ide profiles to vcs
* update ide files
* add status badge and change workflow name
* fix case for docker image tag
* add default dockerfile and change scope
* add packages write permission
* fix tag names in actions
* push only to ghcr
* run only on release tags and nightly
* build only amd64 images
* remove extra copies from typo
* remove old badges
* update actions yaml to build and push docker images
* remove typo
* update readme
* update dockerfiles to newer compiler versions
* fix clang-12 compilation error
* fix clang-12 compilation error
* fix clang-12 compilation error
* fix clang-12 compilation error
* fix clang-12 compilation error
* add clang tidy fixes
* add license badge and update docs url Former-commit-id: 111a547be0b1e752a58abddb6da0c4fbc97bac60 Former-commit-id: 3fe3a7abd1aded64e727ebbc7155de6cb7a14edf Former-commit-id: a624022b7bd50cfc367251d7d1cf5db9d933b0ec
* update to BSD license Former-commit-id: b5aa128c6537916903d5871051bcfe1be65bee2c Former-commit-id: d810ed6a2f7766c88f0be7455b7688b89dfc7b71 Former-commit-id: 92e0c257074d24c61b5739e25443b942f948f8ff
* add gh pages config
* update dependencies and fix related issues for upgrade
* update ide config files
* ignore variable length check
* always return true when fractionToKeep is 1
* use cflags env var directly
* add local cpp env dockerfile
* add local editor files
* add local editor files
* run configure scripts in bash
* add clion cfg files
* add vscode prefs
* fix diagnostics branch case
* revert concurrentqueue version to fix gcc build error
* temporarily ignore gcc warning
* use newly added absl::StatusOr directly
* use htslib's fisher exact impl
* update deps
* cleanup mark ends and print path flow only if present
* use std::fs and allow existing graphs dir
* minor edits
* update dependencies
* add link to post comparing perf of mutex vs spinlocks
* minor edits and revisions
* add version info on startup
* add --verbose option instead of compile time level selection
* add some context for failed assertion
* add log macros
* minor renaming and edits
* use string vector for regions
* use semicolon separated string as regions input
* revert back to uncompressed outvcf for immediate flushing
* write bgzip compressed output vcf
* flush after roughly every 10000bp
* increase required buffer windows
* skip stripping build files in sanitizer images
* remove build files from docker image, run GH action everyday
* edit file watcher outdir
* fix gcc build errors
* remove LTO and remove deps message on build
* rename queue tokens to clarify usage
* reduce IO operations and reuse file handles per thread
* edit log level for messages
* catch align exceptions
* add LTO for gcc builds
* clarify log message
* add terminate handler to prevent deadlock and add more context in logs
* add log message end of microassembler
* use thread id and single letter level fields in logs
* use env vars to get mimalloc stats
* add another failing complex test case
* fix format string
* remove milliseconds from time format
* output uncompressed vcf and check done bits before breaking
* always skip windows with truncated reference sequence
* tag gcc images as latest
* rehash variant store to ensure consistent memory load
* get vcf prefix and always bgzip output vcf
* allow sanitizer build regardless of build type
* remove unused file from build
* write uncompressed vcf by default
* handle non-ref ends in ProcessPath, skip missing nodes
* check revcomp explicitly and ignore missing buddy neighbours
* continue when neighbour is nullptr
* check in inner remaining loop before merging
* remove alignment gap assert
* skip compressing data source and sink nodes
* add more debug asserts
* continue on errors to debug
* add sanitizer blacklist file
* fix typo and reorder deps
* use alpine linux for release builds after SIGILL fix
* add sha and ref tags only for clang release builds
* include integration test data set
* resolve typo in config
* add thread annotations for tsan
* fix tags for docker images
* run CI/CD only manually
* re-add fixed actions config
* remove config to fix actions trigger issue
* point to right repo name
* add ghub actions config
* cleanup lists and remove unused packages
* change sanitizer build compiler flags and add dockerfiles
* remove lto, remove mimalloc in sanitizer builds
* fix clang builds
* add extra check in debug build
* fix typo in condition
* throw exception to debug state
* flush variants more frequently
* move to debug messages
* use reference order in header or fasta
* add informative log and error message
* log stderr to show feedback without buffer
* initial commit with c++17 codebase

### New Features

* also check for non repeat kmer in refseq
* do some basic read filtering on normal
* add left and right flank haplotypes for coverage count
* require atleast 25% overlap to include read in window
* use avg base qual for both snvs and indels
* reduce min tumor vaf callable
* add low avg base qual filter and info fields
* add contig header lines to vcf output
* write bgzf compressed vcf and auto index at end
* use x86 and arm specific pause/yield instructions
* add flag to use only fully contained reads
* skip adding reads not overlapping region
* use weighted harmonic mean to merge node counts
* write per window contigs fasta
* write one path flow dot file with different hues
* add option for cpu profiling
* use spinlock instead of mutex & use relaxed lock when blocking is not needed
* add option to use overlapping reads to build graph
* catch and rethrow thread exceptions to show failures
* use spdlog instead of custom logger
* use concurrent queue for better window result and progress
* add spython converted singularity recipes
* use concurrent queue for pull-based worker model

### Performance Improvements

* batch variants/results to reduce lock contention
* use bool array to reduce allocs
* use inlined vector to reduce allocs for small path builders
* add consumer token when dequeueing windows
* use shared_ptrs to reduce window copies

