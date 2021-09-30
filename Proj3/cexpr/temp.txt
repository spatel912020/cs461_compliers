%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int list_type;
%}

%option       noyywrap nounput yylineno
%x            COMMENT PARA PRE OL UL LI LIO

%%

"<h1>".*"</h1>" {
    yytext[yyleng-5] = 0;
    printf( "\\section{%s}", yytext+4);
}

"<h2>".*"</h2>" {
    yytext[yyleng-5] = 0;
    printf( "\\subsection{%s}", yytext+4);
}

"<h3>".*"</h3>" {
    yytext[yyleng-5] = 0;
    printf( "\\subsubsection{%s}", yytext+4);
}

"<pre>" {
    printf( "\\begin{verbatim}" );
	BEGIN PRE;
}

<PRE>[\n](\r)? {
	printf( "\n" );
}

<PRE>. {
	printf( "%s", yytext);
}


<PRE>"</pre>" {
	printf( "\\end{verbatim}\n");
    BEGIN 0;
}

"<p>" {
    yytext[yyleng-4] = 0;
    printf( "%s", yytext+3);
	BEGIN PARA;
}

"<ul>" {
    printf( "\\begin{itemize}");
	BEGIN UL;
}

"<ol>" {
    printf( "\\begin{enumerate}");
	BEGIN OL;
}

<UL>"<li>" {
	printf("\\item ");
	BEGIN LI;
}

<OL>"<li>" {
	printf("\\item ");
	BEGIN LIO;
}

<LI>"</li>" {
	printf("\n");
	BEGIN UL;
}

<LIO>"</li>" {
	printf("\n");
	BEGIN OL;
}

<UL>"</ul>" {
	printf("\\end{itemize}\n");
	BEGIN 0;
}

<OL>"</ol>" {
	printf("\\end{enumerate}\n");
	BEGIN 0;
}

<LI,LIO>"<big>" {
	printf( "{\\Large ");
}

<LI,LIO>"</big>" {
	printf( "}");
}

<LI,LIO>"<small>" {
	printf( "{\\scriptsize ");
}

<LI,LIO>"</small>" {
	printf( "}");
}

<LI,LIO>"<b>" {
	printf( "\\textbf{");
}

<LI,LIO>"</b>" {
	printf( "}");
}

<LI,LIO>"<i>" {
	printf( "\\textit{");
}

<LI,LIO>"</i>" {
	printf( "}");
}

<LI,LIO>"<strong>" {
	printf( "\\textmd{");
}

<LI,LIO>"</strong>" {
	printf( "}");
}

<LI,LIO>"<em>" {
	printf( "\\emph{");
}

<LI,LIO>"</em>" {
	printf( "}");
}

<LI,LIO>"<sup>" {
	printf( "\\textsuperscript{");
}

<LI,LIO>"</sup>" {
	printf( "}");
}

<LI,LIO>"<sub>" {
	printf( "\\textsubscript{");
}

<LI,LIO>"</sub>" {
	printf( "}");
}

<PARA>"<big>" {
	printf( "{\\Large ");
}

<PARA>"</big>" {
	printf( "}");
}

<PARA>"<small>" {
	printf( "{\\scriptsize ");
}

<PARA>"</small>" {
	printf( "}");
}

<PARA>"<b>" {
	printf( "\\textbf{");
}

<PARA>"</b>" {
	printf( "}");
}

<PARA>"<i>" {
	printf( "\\textit{");
}

<PARA>"</i>" {
	printf( "}");
}

<PARA>"<strong>" {
	printf( "\\textmd{");
}

<PARA>"</strong>" {
	printf( "}");
}

<PARA>"<em>" {
	printf( "\\emph{");
}

<PARA>"</em>" {
	printf( "}");
}

<PARA>"<sup>" {
	printf( "\\textsuperscript{");
}

<PARA>"</sup>" {
	printf( "}");
}

<PARA>"<sub>" {
	printf( "\\textsubscript{");
}

<PARA>"</sub>" {
	printf( "}");
}

<PARA>"</p>" {
	printf( "\n");
	printf( "\n");
	BEGIN 0;
}

"<!--" {
    printf( "%% " );
    BEGIN COMMENT;
}

[ \t\n\r]+ {
}

. {
    fprintf( stderr, "Unexpected input at line %d: '%s'\n", yylineno, yytext );
    exit( 1 );
}

<COMMENT>"-->" {
    printf( "\n" );
    BEGIN 0;
}

<COMMENT>[\n](\r)? {
    printf( "\n%% " );
}

<COMMENT>[ \t] {
    printf( "%s", yytext );
}

<COMMENT>. {
    printf( "%s", yytext );
}

%%

/**************************************************************************
 * The main function for the HTML to LateX converter. Here we do three
 * things:
 *  1. Print out the LateX document header.
 *  2. Invoke the lexer to print out the LateX document
 *  3. Print out the LateX footer.
 *************************************************************************/
int main( int argc, const char *argv[] ) {
    printf( "\\documentclass[12pt]{article}\n" );
    printf( "\\usepackage{fixltx2e}\n" );
    printf( "\n" );
    printf( "\\setlength{\\parindent}{0.0in}\n" );
    printf( "\\setlength{\\parskip}{0.125in}\n" );
    printf( "\n\n" );
    printf( "\\begin{document}\n" );
    yylex();
    printf( "\\end{document}\n" );
    return 0;
}
