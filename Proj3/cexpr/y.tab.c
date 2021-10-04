/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20170709

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 6 "cexpr.y"
#include <stdio.h>
int regs[26];
int err;
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 13 "cexpr.y"
typedef union {
	long a;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 36 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define NUM 257
#define VARIABLE 258
#define LEFT_SHIFT 259
#define RIGHT_SHIFT 260
#define PLUS_EQUAL 261
#define MINUS_EQUAL 262
#define MUL_EQUAL 263
#define DIV_EQUAL 264
#define MOD_EQUAL 265
#define DUMP 266
#define CLEAR 267
#define LEFT_SHIFT_EQUAL 268
#define RIGHT_SHIFT_EQUAL 269
#define AND_EQUAL 270
#define XOR_EQUAL 271
#define OR_EQUAL 272
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    0,    0,    2,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,
};
static const YYINT yylen[] = {                            2,
    0,    2,    3,    2,    2,    1,    3,    3,    3,    3,
    3,    3,    2,    2,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    1,    1,
};
static const YYINT yydefred[] = {                         0,
   31,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    4,    5,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    2,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   12,
    3,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
static const YYINT yydgoto[] = {                          8,
    9,   10,
};
static const YYINT yysindex[] = {                       -40,
    0,  -57,  -50,  -44,  -29,  -29,  -29,  -29,  -12,  -39,
  -29,  -29,  -29,  -29,  -29,  -29,  -29,  -29,  -29,  -29,
  -29,    0,    0,  -10,  -24,  -12,  -30,  -29,  -29,  -29,
  -29,  -29,  -29,  -29,  -29,  -29,  -29,    0,  -12,  -12,
  -12,  -12,  -12,  -12,  -12,  -12,  -12,  -12,  -12,    0,
    0,  -12,  -12,  -10,  -10,  -37,  -37,  -37,  -12,  -12,
  -12,
};
static const YYINT yyrindex[] = {                        22,
    0,  -35,    0,    0,    0,    0,    0,    0,  -23,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    9,    0,   31,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   33,   37,
   39,   40,   44,   47,   54,   67,   86,   87,   88,    0,
    0,   89,   90,   17,   32,   -3,    4,   24,  101,  102,
  103,
};
static const YYINT yygindex[] = {                         0,
  104,   35,
};
#define YYTABLESIZE 250
static const YYINT yytable[] = {                          6,
   35,   32,   32,   21,    5,   32,   32,   32,   22,   32,
    6,   32,   34,   35,   23,    5,   50,   32,   30,   38,
   31,    1,   33,   32,   34,   35,   34,   35,   51,   32,
   30,   32,   31,    9,   33,    6,   33,    9,    9,    9,
   10,    9,   27,    9,   10,   10,   10,    0,   10,   13,
   10,   13,    0,   13,    0,    9,   36,    7,   32,    7,
   11,    7,   10,    0,   11,   11,   11,   13,   11,   36,
   11,   14,    8,   21,    8,    7,    8,   22,    0,   23,
   24,   36,   11,   36,   30,    7,   37,   25,   32,   14,
    8,   21,    0,    0,   26,   22,    7,   23,   24,   37,
    0,    0,   30,    0,    0,   25,    0,   27,   24,   25,
   26,   37,   26,   37,   39,   40,   41,   42,   43,   44,
   45,   46,   47,   48,   49,   27,   28,   29,   20,   15,
   16,   52,   53,   54,   55,   56,   57,   58,   59,   60,
   61,   17,   18,   19,   28,   29,   20,   15,   16,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   17,
   18,   19,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   11,   12,   13,   14,   15,    0,    0,
   16,   17,   18,   19,   20,    0,    1,    2,    0,    0,
    0,   28,   29,   32,   32,    3,    4,    1,    2,    0,
    0,    0,    0,    0,   28,   29,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   28,   29,   28,   29,
};
static const YYINT yycheck[] = {                         40,
   38,   37,   38,   61,   45,   41,   42,   43,   59,   45,
   40,   47,   37,   38,   59,   45,   41,   42,   43,   59,
   45,    0,   47,   59,   37,   38,   37,   38,   59,   42,
   43,   42,   45,   37,   47,   59,   47,   41,   42,   43,
   37,   45,    8,   47,   41,   42,   43,   -1,   45,   41,
   47,   43,   -1,   45,   -1,   59,   94,   41,   94,   43,
   37,   45,   59,   -1,   41,   42,   43,   59,   45,   94,
   47,   41,   41,   41,   43,   59,   45,   41,   -1,   41,
   41,   94,   59,   94,   41,  126,  124,   41,  124,   59,
   59,   59,   -1,   -1,   41,   59,  126,   59,   59,  124,
   -1,   -1,   59,   -1,   -1,   59,   -1,   41,    5,    6,
    7,  124,   59,  124,   11,   12,   13,   14,   15,   16,
   17,   18,   19,   20,   21,   59,   41,   41,   41,   41,
   41,   28,   29,   30,   31,   32,   33,   34,   35,   36,
   37,   41,   41,   41,   59,   59,   59,   59,   59,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,
   59,   59,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  261,  262,  263,  264,  265,   -1,   -1,
  268,  269,  270,  271,  272,   -1,  257,  258,   -1,   -1,
   -1,  259,  260,  259,  260,  266,  267,  257,  258,   -1,
   -1,   -1,   -1,   -1,  259,  260,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  259,  260,  259,  260,
};
#define YYFINAL 8
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 272
#define YYUNDFTOKEN 277
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,
0,"';'",0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'|'",0,"'~'",0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"NUM","VARIABLE","LEFT_SHIFT","RIGHT_SHIFT","PLUS_EQUAL",
"MINUS_EQUAL","MUL_EQUAL","DIV_EQUAL","MOD_EQUAL","DUMP","CLEAR",
"LEFT_SHIFT_EQUAL","RIGHT_SHIFT_EQUAL","AND_EQUAL","XOR_EQUAL","OR_EQUAL",0,0,0,
0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : commands",
"commands :",
"commands : command ';'",
"commands : commands command ';'",
"commands : DUMP ';'",
"commands : CLEAR ';'",
"command : expr",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : '(' expr ')'",
"expr : '-' expr",
"expr : '~' expr",
"expr : expr LEFT_SHIFT expr",
"expr : expr RIGHT_SHIFT expr",
"expr : expr '&' expr",
"expr : expr '^' expr",
"expr : expr '|' expr",
"expr : VARIABLE '=' expr",
"expr : VARIABLE PLUS_EQUAL expr",
"expr : VARIABLE MINUS_EQUAL expr",
"expr : VARIABLE MUL_EQUAL expr",
"expr : VARIABLE DIV_EQUAL expr",
"expr : VARIABLE LEFT_SHIFT_EQUAL expr",
"expr : VARIABLE RIGHT_SHIFT_EQUAL expr",
"expr : VARIABLE AND_EQUAL expr",
"expr : VARIABLE XOR_EQUAL expr",
"expr : VARIABLE OR_EQUAL expr",
"expr : VARIABLE MOD_EQUAL expr",
"expr : NUM",
"expr : VARIABLE",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 124 "cexpr.y"

main()
{
   if (yyparse())
   printf("\nInvalid expression.\n");
   else
   printf("\nCalculator off.\n");
}

yyerror(s)
char *s;
{
   fprintf(stderr, "%s\n", s);
}
#line 295 "y.tab.c"

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yym = 0;
    yyn = 0;
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        yychar = YYLEX;
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);

    switch (yyn)
    {
case 2:
#line 38 "cexpr.y"
	{err = 0;}
break;
case 3:
#line 39 "cexpr.y"
	{err = 0;}
break;
case 4:
#line 40 "cexpr.y"
	{
				for(int i = 0; i < 26; i++){
					printf("%c = %d\n", i+'a', regs[i]);
				}
			}
break;
case 5:
#line 45 "cexpr.y"
	{	
					for(int i = 0; i < 26; i++){
						regs[i] = 0;
					}
				}
break;
case 6:
#line 52 "cexpr.y"
	{ if(err == 1){} else{printf("%d\n", yyval);};}
break;
case 7:
#line 55 "cexpr.y"
	{ 
								if( (yystack.l_mark[-2].a + yystack.l_mark[0].a) > 2147483647){
									fprintf(stderr, "overflow\n");
									err = 1;
								}
								else{
									yyval.a = yystack.l_mark[-2].a + yystack.l_mark[0].a;
								}
							}
break;
case 8:
#line 65 "cexpr.y"
	{	
							if( (yystack.l_mark[-2].a + yystack.l_mark[0].a) > 2147483647){
								fprintf(stderr, "overflow\n");
								err = 1;
							}
							else{
								yyval.a = yystack.l_mark[-2].a - yystack.l_mark[0].a;
							}	
						 }
break;
case 9:
#line 75 "cexpr.y"
	{
							if( (yystack.l_mark[-2].a * yystack.l_mark[0].a) > 2147483647){
								fprintf(stderr, "overflow\n");
								err = 1;
							}
							else{
								yyval.a = yystack.l_mark[-2].a * yystack.l_mark[0].a;
							}
						}
break;
case 10:
#line 85 "cexpr.y"
	{ 
							if(yystack.l_mark[0].a == 0){ 
								printf("dividebyzero\n");
								err = 1;
							}
							else if(yystack.l_mark[-2].a / yystack.l_mark[0].a > 2147483647){
								fprintf(stderr, "overflow\n");
								err = 1;	
							}
							else{
								yyval.a = yystack.l_mark[-2].a / yystack.l_mark[0].a;
							}
						}
break;
case 11:
#line 99 "cexpr.y"
	{ yyval.a = yystack.l_mark[-2].a % yystack.l_mark[0].a;}
break;
case 12:
#line 100 "cexpr.y"
	{ yyval.a = (yystack.l_mark[-1].a);}
break;
case 13:
#line 101 "cexpr.y"
	{ yyval.a = - yystack.l_mark[0].a; }
break;
case 14:
#line 102 "cexpr.y"
	{ yyval.a = ~yystack.l_mark[0].a; }
break;
case 15:
#line 103 "cexpr.y"
	{ yyval.a = yystack.l_mark[-2].a << yystack.l_mark[0].a;}
break;
case 16:
#line 104 "cexpr.y"
	{ yyval.a = yystack.l_mark[-2].a >> yystack.l_mark[0].a;}
break;
case 17:
#line 105 "cexpr.y"
	{ yyval.a = yystack.l_mark[-2].a & yystack.l_mark[0].a;}
break;
case 18:
#line 106 "cexpr.y"
	{ yyval.a = yystack.l_mark[-2].a ^ yystack.l_mark[0].a;}
break;
case 19:
#line 107 "cexpr.y"
	{ yyval.a = yystack.l_mark[-2].a | yystack.l_mark[0].a;}
break;
case 20:
#line 108 "cexpr.y"
	{ regs[yystack.l_mark[-2].a] = yystack.l_mark[0].a; yyval.a = regs[yystack.l_mark[-2].a];}
break;
case 21:
#line 109 "cexpr.y"
	{ regs[yystack.l_mark[-2].a] += yystack.l_mark[0].a; yyval.a = regs[yystack.l_mark[-2].a];}
break;
case 22:
#line 110 "cexpr.y"
	{ regs[yystack.l_mark[-2].a] -= yystack.l_mark[0].a; yyval.a = regs[yystack.l_mark[-2].a];}
break;
case 23:
#line 111 "cexpr.y"
	{ regs[yystack.l_mark[-2].a] *= yystack.l_mark[0].a; yyval.a = regs[yystack.l_mark[-2].a];}
break;
case 24:
#line 112 "cexpr.y"
	{ regs[yystack.l_mark[-2].a] /= yystack.l_mark[0].a; yyval.a = regs[yystack.l_mark[-2].a];}
break;
case 25:
#line 113 "cexpr.y"
	{regs[yystack.l_mark[-2].a] <<= yystack.l_mark[0].a; yyval.a = regs[yystack.l_mark[-2].a];}
break;
case 26:
#line 114 "cexpr.y"
	{regs[yystack.l_mark[-2].a] >>= yystack.l_mark[0].a; yyval.a = regs[yystack.l_mark[-2].a];}
break;
case 27:
#line 115 "cexpr.y"
	{regs[yystack.l_mark[-2].a] &= yystack.l_mark[0].a; yyval.a = regs[yystack.l_mark[-2].a];}
break;
case 28:
#line 116 "cexpr.y"
	{regs[yystack.l_mark[-2].a] ^= yystack.l_mark[0].a; yyval.a = regs[yystack.l_mark[-2].a];}
break;
case 29:
#line 117 "cexpr.y"
	{regs[yystack.l_mark[-2].a] |= yystack.l_mark[0].a; yyval.a = regs[yystack.l_mark[-2].a];}
break;
case 30:
#line 118 "cexpr.y"
	{ regs[yystack.l_mark[-2].a] %= yystack.l_mark[0].a; yyval.a = regs[yystack.l_mark[-2].a];}
break;
case 31:
#line 119 "cexpr.y"
	{ yyval.a = yystack.l_mark[0].a;}
break;
case 32:
#line 120 "cexpr.y"
	{ yyval.a = regs[yystack.l_mark[0].a];}
break;
#line 662 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            yychar = YYLEX;
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
