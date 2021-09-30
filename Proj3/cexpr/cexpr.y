/*
 * This file defines an example yacc grammar for simple C expressions.
 */

%{
#include <stdio.h>
%}

%union {
  int num;
  char id;
}

%token <num> NUM
%token <id> VARIABLE
%token OPEN_PARENTHESES
%token CLOSE_PARENTHESES
%token BITWISE_NOT
%token MULTIPLICATION
%token DIVISION
%token REMAINDER
%token ADD
%token SUBTRACTION
%token LEFT_SHIFT
%token RIGHT_SHIFT
%token BITWISE_AND
%token BITWISE_XOR
%token BITWISE_OR
%token ASSIGNMENT
%token SEMICOLON
%type <num> expr

%%
commands:
	|	commands command
	;

command	:	expr ';'      { printf("%d\n", $1); }
	;

expr	:	expr '+' NUM    { $$ = $1 + $3; }
	|   expr '-' NUM    { $$ = $1 - $3; }
	|   expr '+' VARIABLE { $$ = $1 + $3; }
	|   expr '-' VARIABLE { $$ = $1 - $3; }
	|	NUM                 { $$ = $1; }
	;

%%

int main()
{
   if (yyparse())
      printf("\nInvalid expression.\n");
   else
      printf("\nCalculator off.\n");
}

int yyerror(s)
char *s;
{
   fprintf(stderr, "%s\n", s);
}
