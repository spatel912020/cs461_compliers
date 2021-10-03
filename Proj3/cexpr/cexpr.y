/*
 * This file defines an example yacc grammar for simple C expressions.
 */

%{
#include <stdio.h>
int regs[26];
int err;
%}

%start commands

%union {
	long a;
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
%token DUMP
%token CLEAR
%token LEFT_SHIFT_EQUAL
%token RIGHT_SHIFT_EQUAL
%token AND_EQUAL
%token XOR_EQUAL
%token OR_EQUAL
%type expr
%left '+' '-' 
%left '*' '/' '%'

%%
commands:
	|	command ';' {err = 0;}
	|	commands command ';' {err = 0;}
	| DUMP ';' {
				for(int i = 0; i < 26; i++){
					printf("%c = %d\n", i+'a', regs[i]);
				}
			}
	| CLEAR ';' {	
					for(int i = 0; i < 26; i++){
						regs[i] = 0;
					}
				}
	;

command	:	expr { if(err == 1){} else{printf("%d\n", $$);};}
	;

expr	:	expr '+' expr    { 
								if( ($1.a + $3.a) > 2147483647){
									fprintf(stderr, "overflow\n");
									err = 1;
								}
								else{
									$$.a = $1.a + $3.a;
								}
							}

	|   expr '-' expr    {	
							if( ($1.a + $3.a) > 2147483647){
								fprintf(stderr, "overflow\n");
								err = 1;
							}
							else{
								$$.a = $1.a - $3.a;
							}	
						 }

	|   expr '*' expr    {
							if( ($1.a * $3.a) > 2147483647){
								fprintf(stderr, "overflow\n");
								err = 1;
							}
							else{
								$$.a = $1.a * $3.a;
							}
						}

	|   expr '/' expr    { 
							if($3.a == 0){ 
								printf("dividebyzero\n");
								err = 1;
							}
							else if($1.a / $3.a > 2147483647){
								fprintf(stderr, "overflow\n");
								err = 1;	
							}
							else{
								$$.a = $1.a / $3.a;
							}
						}

	|   expr '%' expr    { $$.a = $1.a % $3.a;}
	|   '(' expr ')'     { $$.a = ($2.a);}
	|	'-' expr		 { $$.a = - $2.a; }
	|   '~' expr		 { $$.a = ~$2.a; }
	|   expr LEFT_SHIFT expr    { $$.a = $1.a << $3.a;}
	|   expr RIGHT_SHIFT expr    { $$.a = $1.a >> $3.a;}
	|   expr '&' expr    { $$.a = $1.a & $3.a;}
	|   expr '^' expr    { $$.a = $1.a ^ $3.a;}
	|   expr '|' expr    { $$.a = $1.a | $3.a;}
	|	VARIABLE '=' expr { regs[$1.a] = $3.a; $$.a = regs[$1.a];}
	|   VARIABLE PLUS_EQUAL expr { regs[$1.a] += $3.a; $$.a = regs[$1.a];}
	|   VARIABLE MINUS_EQUAL expr    { regs[$1.a] -= $3.a; $$.a = regs[$1.a];}
	|   VARIABLE MUL_EQUAL expr    { regs[$1.a] *= $3.a; $$.a = regs[$1.a];}
	|   VARIABLE DIV_EQUAL expr    { regs[$1.a] /= $3.a; $$.a = regs[$1.a];}
	|   VARIABLE LEFT_SHIFT_EQUAL expr {regs[$1.a] <<= $3.a; $$.a = regs[$1.a];}
	|	VARIABLE RIGHT_SHIFT_EQUAL expr {regs[$1.a] >>= $3.a; $$.a = regs[$1.a];}
	|	VARIABLE AND_EQUAL expr		{regs[$1.a] &= $3.a; $$.a = regs[$1.a];}
	|	VARIABLE XOR_EQUAL expr		{regs[$1.a] ^= $3.a; $$.a = regs[$1.a];}
	|	VARIABLE OR_EQUAL expr		{regs[$1.a] |= $3.a; $$.a = regs[$1.a];}
	|   VARIABLE MOD_EQUAL expr    { regs[$1.a] %= $3.a; $$.a = regs[$1.a];}
	|	NUM                 { $$.a = $1.a;}
	|   VARIABLE			{ $$.a = regs[$1.a];}
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
