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
%token LEFT_SHIFT
%token RIGHT_SHIFT
%token PLUS_EQUAL
%token MINUS_EQUAL
%token MUL_EQUAL
%token DIV_EQUAL
%token MOD_EQUAL
%type expr
%left '|' '&' '+' '-' '*' '/' '%' '<<' '+='
%%
commands:
	|	command ';'
	|	commands command ';'
	;

command	:	expr { printf("%d\n", $1); }
	;

expr	:	expr '+' NUM    { $$.a = $1.a + $3.a; }
	|   expr '-' NUM    { $$.a = $1.a - $3.a; }
	|   expr '*' NUM    { $$.a = $1.a * $3.a; }
	|   expr '/' NUM    { $$.a = $1.a / $3.a; }
	|   expr '%' NUM    { $$.a = $1.a % $3.a; }
	|   expr LEFT_SHIFT NUM    { $$.a = $1.a << $3.a; }
	|   expr RIGHT_SHIFT NUM    { $$.a = $1.a >> $3.a; }
	|   expr '&' NUM    { $$.a = $1.a & $3.a; }
	|   expr '^' NUM    { $$.a = $1.a ^ $3.a; }
	|   expr '|' NUM    { $$.a = $1.a | $3.a; }
	|	VARIABLE '=' expr { regs[$1.a] = $3.a; $$.a = regs[$1.a]; }
	|   VARIABLE PLUS_EQUAL expr { regs[$1.a] += $3.a; $$.a = regs[$1.a];}
	|   VARIABLE MINUS_EQUAL expr    { regs[$1.a] -= $3.a; $$.a = regs[$1.a];}
	|   VARIABLE MUL_EQUAL expr    { regs[$1.a] *= $3.a; $$.a = regs[$1.a];}
	|   VARIABLE DIV_EQUAL expr    { regs[$1.a] /= $3.a; $$.a = regs[$1.a];}
	|   VARIABLE MOD_EQUAL expr    { regs[$1.a] %= $3.a; $$.a = regs[$1.a];}
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
