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

<UL>"</ul>" {
	printf("\\end{itemize}\n");
	BEGIN 0;
}

"<ol>" {
    printf( "\\begin{enumerate}");
	BEGIN OL;
}

<OL>"</ol>" {
	printf("\\end{enumerate}\n");
	BEGIN 0;
}

<OL>"<li>" {
	printf("\\item ");
	BEGIN LIO;
}

<UL>"<li>" {
	printf("\\item ");
	BEGIN LI;
}

<LIO>"</li>" {
	printf("\n");
	BEGIN OL;
}

<LI>"</li>" {
	printf("\n");
	BEGIN UL;
}

<LIO>"<big>" {
	printf( "{\\Large ");
}

<LIO>"</big>" {
	printf( "}");
}

<LIO>"</big>" {
	printf( "}");
}

<LIO>"<small>" {
	printf( "{\\scriptsize ");
}

<LIO>"</small>" {
	printf( "}");
}

<LIO>"<b>" {
	printf( "\\textbf{");
}

<LIO>"</b>" {
	printf( "}");
}

<LIO>"<i>" {
	printf( "\\textit{");
}

<LIO>"</i>" {
	printf( "}");
}

<LIO>"<strong>" {
	printf( "\\textmd{");
}

<LIO>"</strong>" {
	printf( "}");
}

<LIO>"<em>" {
	printf( "\\emph{");
}

<LIO>"</em>" {
	printf( "}");
}

<LIO>"<sup>" {
	printf( "\\textsuperscript{");
}

<LIO>"</sup>" {
	printf( "}");
}

<LIO>"<sub>" {
	printf( "\\textsubscript{");
}

<LIO>"</sub>" {
	printf( "}");
}

<LI>"<big>" {
	printf( "{\\Large ");
}

<LI>"</big>" {
	printf( "}");
}

<LI>"<small>" {
	printf( "{\\scriptsize ");
}

<LI>"</small>" {
	printf( "}");
}

<LI>"<b>" {
	printf( "\\textbf{");
}

<LI>"</b>" {
	printf( "}");
}

<LI>"<i>" {
	printf( "\\textit{");
}

<LI>"</i>" {
	printf( "}");
}

<LI>"<strong>" {
	printf( "\\textmd{");
}

<LI>"</strong>" {
	printf( "}");
}

<LI>"<em>" {
	printf( "\\emph{");
}

<LI>"</em>" {
	printf( "}");
}

<LI>"<sup>" {
	printf( "\\textsuperscript{");
}

<LI>"</sup>" {
	printf( "}");
}

<LI>"<sub>" {
	printf( "\\textsubscript{");
}

<LI>"</sub>" {
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
