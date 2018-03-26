%{
/* C++ string header, for string ops below */
#include <string>
#include <cstdlib>

/* Implementation of yyFlexScanner */ 
#include "TotsScanner.h"

using namespace Tots::Language::Syntax::Parser;

#undef  YY_DECL
#define YY_DECL int TotsScanner::yylex( TotsParser::semantic_type * const lval)

/* typedef to make the returns for the tokens shorter */
using token = TotsParser::token;

/* define yyterminate as this instead of NULL */
//#define yyterminate() return( token::END )

/* msvc2010 requires that we exclude this header file. */
#define YY_NO_UNISTD_H

/* update location on matching */
//#define YY_USER_ACTION loc->step(); loc->columns(yyleng);

%}

%option nodefault
%option yyclass="Tots::Language::Syntax::Parser::TotsScanner"
%option noyywrap
%option c++

%%
%{          /** Code executed at the beginning of yylex **/
            yylval = lval;
%}

[ \t\n]+             { /* skip */ }

"var"					{ return token::_VAR; }

"void"					{ return token::_VOID; }
"int"					{ return token::_INT; }
"float"					{ return token::_FLOAT; }
"bool"					{ return token::_BOOL; }
"char"					{ return token::_CHAR; }

"("		                { return token::_LPAREN; }
")"		                { return token::_RPAREN; }
"{"		                { return token::_LCURLY; }
"}"		                { return token::_RCURLY; }
","		                { return token::_COMMA; }
"."		                { return token::_DOT; }
";"		                { return token::_SEMICOLON; }
"="			            { return token::_EQ; }
"+"						{ return token::_ADD; }
"-"						{ return token::_SUB; }
"*"						{ return token::_MUL; }
"/"						{ return token::_DIV; }
"+="					{ return token::_ADD_EQ; }
"-="					{ return token::_SUB_EQ; }
"*="					{ return token::_MUL_EQ; }
"/="					{ return token::_DIV_EQ; }
[a-zA-Z][a-zA-Z0-9]*	{ yylval->build<std::string>(yytext); return token::_ID; }
[0-9]+		{ int i = atoi(yytext); yylval->build<unsigned long>(*(unsigned long *)&i); return token::_INT_LITERAL; }
.
%%


