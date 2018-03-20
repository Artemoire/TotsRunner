%option noyywrap
%{
	#include "TotsParser.h"
	#include <string.h>

	YY_BUFFER_STATE my_buffer;
%}

%%

[ \t\n]+             { /* skip */ }

"var"					{ return _VAR; }

"void"					{ return _VOID; }
"int"					{ return _INT; }
"float"					{ return _FLOAT; }
"bool"					{ return _BOOL; }
"char"					{ return _CHAR; }

"("		                { return _LPAREN; }
")"		                { return _RPAREN; }
"{"		                { return _LCURLY; }
"}"		                { return _RCURLY; }
","		                { return _COMMA; }
"."		                { return _DOT; }
";"		                { return _SEMICOLON; }
"="			            { return _EQ; }
"+"						{ return _ADD; }
"-"						{ return _SUB; }
"*"						{ return _MUL; }
"/"						{ return _DIV; }
"+="					{ return _ADD_EQ; }
"-="					{ return _SUB_EQ; }
"*="					{ return _MUL_EQ; }
"/="					{ return _DIV_EQ; }

[a-zA-Z][a-zA-Z0-9]*	{ yylval.id = _strdup(yytext); return _ID; }
[0-9]+		{ int i = atoi(yytext); yylval.WRD = *(unsigned long *)&i; return _INT_LITERAL; }
.
%%

void scan_string_prepare(char * tstr, int size)
{
	my_buffer = yy_scan_buffer(tstr, size);
	yylex();
}

void scan_string_release()
{
	yy_delete_buffer(my_buffer);
}