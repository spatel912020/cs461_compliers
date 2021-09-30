#define NUM 257
#define VARIABLE 258
#define LEFT_SHIFT 259
#define RIGHT_SHIFT 260
#define PLUS_EQUAL 261
#define MINUS_EQUAL 262
#define MUL_EQUAL 263
#define DIV_EQUAL 264
#define MOD_EQUAL 265
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	int a;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
