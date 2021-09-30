%{
#include "y.tab.h"
int c;

%}
%%
[0-9]+		{sscanf(yytext, "%d", &yylval.a); return NUM; }
[a-z]		{c = yytext[0]; yylval.a = c- 'a'; return VARIABLE; }
[ \t\n]		{;}
"<<"		{return LEFT_SHIFT;}
">>"		{return RIGHT_SHIFT;}
"+="		{return PLUS_EQUAL;}
"-="		{return MINUS_EQUAL;}
"*="		{return MUL_EQUAL;}
"/="		{return DIV_EQUAL;}
"%="		{return MOD_EQUAL;}
[^0-9a-z\b]	{return(yytext[0]);}
.			{printf("Unrecognized token\n;"); return -1;}
%%

