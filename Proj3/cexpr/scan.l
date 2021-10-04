%{
#include "y.tab.h"
int c;

%}
%%
[0-9]+		{sscanf(yytext, "%d", &yylval.a); return NUM; }
[a-z]		{c = yytext[0]; yylval.a = c- 'a'; return VARIABLE; }
[ \t\n]		{;}
"+="		{return PLUS_EQUAL;}
"-="		{return MINUS_EQUAL;}
"*="		{return MUL_EQUAL;}
"/="		{return DIV_EQUAL;}
"%="		{return MOD_EQUAL;}
"<<="		{return LEFT_SHIFT_EQUAL;}
">>="		{return RIGHT_SHIFT_EQUAL;}
"&="		{return AND_EQUAL;}
"^="		{return XOR_EQUAL;}
"|="		{return OR_EQUAL;}
"<<"		{return LEFT_SHIFT;}
">>"		{return RIGHT_SHIFT;}
"dump"		{return DUMP;}
"clear"		{return CLEAR;}
[^0-9a-z\b]	{return(yytext[0]);}
.			{printf("Unrecognized token\n;"); return -1;}
%%

