%{
#include "y.tab.h"
%}
%%
[0-9]+		{sscanf(yytext, "%d", &yylval.num); return NUM; }
[a-z]		{sscanf(yytext, "%c", &yylval.id); return VARIABLE; }
"("			{return OPEN_PARENTHESES;}
")"			{return CLOSE_PARENTHESES;}
"~"			{return BITWISE_NOT;}
"*"			{return MULTIPLICATION;}
"/"			{return DIVISION;}
"%"			{return REMAINDER;}
"+"			{return ADD;}
"-"			{return SUBTRACTION;}
"<<"		{return LEFT_SHIFT;}
">>"		{return RIGHT_SHIFT;}
"&"			{return BITWISE_AND;}
"^"			{return BITWISE_XOR;}
"|"			{return BITWISE_OR;}
"="			{return ASSIGNMENT;}
";"			{return SEMICOLON;}
[ \t\n]		{;}
.			{return yytext[0]; }
%%
