.DELETE_ON_ERROR:

COMMON_FLOAT = \
  _atof.c \
  _schar2fs.c \
  _sint2fs.c \
  _slong2fs.c \
  _slonglong2fs.c \
  _uchar2fs.c \
  _uint2fs.c \
  _ulong2fs.c \
  _ulonglong2fs.c \
  _fs2schar.c \
  _fs2sint.c \
  _fs2slong.c \
  _fs2uchar.c \
  _fs2uint.c \
  _fs2ulong.c \
  _fsadd.c \
  _fsdiv.c \
  _fsmul.c \
  _fssub.c \
  _fseq.c \
  _fslt.c \
  _fsneq.c \
  fabsf.c \
  frexpf.c \
  ldexpf.c \
  expf.c \
  powf.c \
  sincosf.c \
  sinf.c \
  cosf.c \
  logf.c \
  log10f.c \
  sqrtf.c \
  tancotf.c \
  tanf.c \
  cotf.c \
  asincosf.c \
  asinf.c \
  acosf.c \
  atanf.c \
  atan2f.c \
  sincoshf.c \
  sinhf.c \
  coshf.c \
  tanhf.c \
  floorf.c \
  ceilf.c \
  modff.c \
  errno.c \
  isinf.c \
  isnan.c

COMMON_LONG = \
  _divslong.c \
  _modslong.c \
  _modulong.c

COMMON_SDCC = \
  isalnum.c \
  isalpha.c \
  isblank.c \
  iscntrl.c \
  isdigit.c \
  isgraph.c \
  islower.c \
  isprint.c \
  ispunct.c \
  isspace.c \
  isupper.c \
  isxdigit.c \
  tolower.c \
  toupper.c \
  atoi.c \
  atol.c \
  atoll.c \
  strtol.c \
  strtoul.c \
  bsearch.c \
  qsort.c \
  abs.c \
  labs.c \
  rand.c \
  _strcat.c \
  _strchr.c \
  _strcspn.c \
  strdup.c \
  strndup.c \
  _strncat.c \
  _strncmp.c \
  strxfrm.c \
  _strncpy.c \
  _strpbrk.c \
  _strrchr.c \
  _strspn.c \
  _strstr.c \
  _strtok.c \
  memccpy.c \
  _memchr.c \
  _memcmp.c \
  _memset.c \
  memset_explicit.c \
  aligned_alloc.c \
  calloc.c \
  malloc.c \
  realloc.c \
  free.c \
  mblen.c \
  mbtowc.c \
  wctomb.c \
  mbstowcs.c \
  wcstombs.c \
  mbrtoc16.c \
  c16rtomb.c \
  mbrtoc32.c \
  c32rtomb.c \
  mbstoc16s.c \
  c16stombs.c \
  wcscmp.c \
  wcslen.c \
  btowc.c \
  wctob.c \
  mbsinit.c \
  mbrlen.c \
  mbrtowc.c \
  wcrtomb.c \
  printf_large.c \
  puts.c \
  gets.c \
  __assert.c \
  time.c

MODELS = small medium large huge

CC = ${abs_top_builddir}/bin/sdcc
SDAR = ${abs_top_builddir}/bin/sdar

%.rel: %.c
	$(CC) $(CFLAGS) ${EXTRA_CFLAGS} -c $<

%.rel: ../%.c
	$(CC) $(CFLAGS) ${EXTRA_CFLAGS} -c $<
