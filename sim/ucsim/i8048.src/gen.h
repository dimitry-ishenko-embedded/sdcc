
#define GEN_DIS_ENTRY(CODE,MNEMO,BRANCH,LEN,ISCALL,TICKS,INFO)	\
  { CODE, 0xff, BRANCH, LEN, MNEMO, ISCALL, TICKS, INFO },

#define GEN_METHOD_DECL(CODE,METHOD)		\
  virtual int instruction_## CODE (t_mem code);

#define GEN_ALIAS_DEFS(CODE,METHOD)		\
  define METHOD		instruction_## CODE

#ifdef GEN_DIS
#define DEC(CODE,METHOD,MNEMO,BRANCH,LEN,ISCALL,TICKS,INFO)		\
  GEN_DIS_ENTRY(0x## CODE ,MNEMO,BRANCH,LEN,ISCALL,TICKS,INFO)
#endif

#ifdef GEN_METHOD
#define DEC(CODE,METHOD,MNEMO,BRANCH,LEN,ISCALL,TICKS,INFO)	\
  GEN_METHOD_DECL(CODE,METHOD)
#endif

#ifdef GEN_ALIAS
#define DEC(CODE,METHOD,MNEMO,BRANCH,LEN,ISCALL,TICKS,INFO)	\
  GEN_ALIAS_DEFS(CODE,METHOD)
#endif
