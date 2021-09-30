%{
#include "y.tab.h"
int c;

%}
%%
[0-9]+		{sscanf(yytext, "%d", &yylval.a); return NUM; }
[a-z]		{c = yytext[0]; yylval.a = c- 'a'; return VARIABLE; }
[ \t\n]		{;}
[^0-9a-z\b]	{return(yytext[0]);}
.			{printf("Unrecognized token\n;"); return -1;}
%%

