/*
 * This file defines an example yacc grammar for simple C expressions.
 */

%{
#include <stdio.h>

int regs[26];

%}

%start commands

%union {
	int a;
}
%token NUM
%token VARIABLE
%type expr
%left '|' '&' '+' '-' '*' '/' '%'

%%
commands:
	|	command ';'
	|	commands command ';'
	;

command	:	expr { printf("%d\n", $1); }
	|	VARIABLE '=' expr { regs[$1.a] = $3.a; }
	;

expr	:	expr '+' NUM    { $$.a = $1.a + $3.a; }
	|   expr '-' NUM    { $$.a = $1.a - $3.a; }
	|   expr '*' NUM    { $$.a = $1.a * $3.a; }
	|   expr '/' NUM    { $$.a = $1.a / $3.a; }
	|   expr '%' NUM    { $$.a = $1.a % $3.a; }
	|   expr '<<' NUM    { $$.a = $1.a << $3.a; }
	|   expr '>>' NUM    { $$.a = $1.a >> $3.a; }
	|   expr '&' NUM    { $$.a = $1.a & $3.a; }
	|   expr '^' NUM    { $$.a = $1.a ^ $3.a; }
	|   expr '|' NUM    { $$.a = $1.a | $3.a; }
	|   expr '+=' NUM    { $$.a = $1.a += $3.a; }
	|   expr '-=' NUM    { $$.a = $1.a -= $3.a; }
	|   expr '*=' NUM    { $$.a = $1.a *= $3.a; }
	|   expr '/=' NUM    { $$.a = $1.a /= $3.a; }
	|   expr '%=' NUM    { $$.a = $1.a %= $3.a; }
	|	NUM                 { $$ = $1; }
	|   VARIABLE			{ $$.a = regs[$1.a]; }
	;

%%

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
