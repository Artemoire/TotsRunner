%skeleton "lalr1.cc"
%require  "3.0"
%defines 
%define api.namespace {Tots::Language::Syntax::Parser}
%define parser_class_name {TotsParser}

%code requires{
	#include <vector>

	#include "SyntaxRoot.h"  
	#include "VariableDeclaratorSyntax.h"
	#include "MemberDeclarationSyntax.h"
		
	#include "VisibilityModifierSyntax.h"
	#include "StaticModifierSyntax.h"

	#include "ArgumentSyntax.h"
	#include "StatementSyntax.h"

	#include "SyntaxError.h"

	namespace Tots
	{	
		namespace Language
		{
			namespace Syntax
			{
				namespace Parser
				{
					class TotsParserDriver;
					class TotsScanner;
				}
			}
		}		
	}

// The following definitions is missing when %locations isn't used
# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

}

%parse-param { TotsScanner  &scanner  }
%parse-param { TotsParserDriver  &driver  }

%code {
	#include <iostream>
	#include <cstdlib>
	#include <fstream>
	#include <vector>  

	/* include for all driver functions */
	#include "TotsParserDriver.h"

	using namespace Tots::Language::Syntax::Parser;
	using namespace std;

	#include "ExpressionSyntaxDefs.h"
	#include "StatementSyntaxDefs.h"
	#include "TypeSyntaxDefs.h"
	#include "LiteralSyntaxDefs.h"
	#include "NameSyntaxDefs.h"
	#include "MemberDeclarationDefs.h"
	#include "TypeDeclarationDefs.h"
	#include "ArgumentSyntax.h"

#undef yylex
#define yylex scanner.yylex
}

%define api.value.type variant
%define parse.assert

%start root

%token _NAMESPACE
%token _CLASS

%token _INTERNAL
%token _PRIVATE
%token _PROTECTED
%token _PUBLIC

%token _STATIC

%token _VAR
%token _VOID
%token _INT
%token _FLOAT
%token _BOOL
%token _CHAR
%token _LPAREN
%token _RPAREN
%token _LCURLY
%token _RCURLY
%token _COMMA
%left _DOT
%token _SEMICOLON
%right _EQ _ADD_EQ _SUB_EQ _MUL_EQ _DIV_EQ
%left _ADD _SUB
%left _MUL _DIV
%token <std::string> _ID
%token <unsigned long> _INT_LITERAL

%type <SyntaxRoot*> root

%type <NameSyntax*> name
%type <SimpleNameSyntax*> simple_name

%type <std::vector<MemberDeclarationSyntax*>*> base_decl_list
%type <MemberDeclarationSyntax*> base_decl
%type <MemberDeclarationSyntax*> namespace_decl
%type <MemberDeclarationSyntax*> class_decl

%type <VisibilityModifierSyntax*> visibility_mod
%type <StaticModifierSyntax*> static_mod

%type <std::vector<MemberDeclarationSyntax*>*> member_decl_list
%type <MemberDeclarationSyntax*> member_decl

%type <MemberDeclarationSyntax*> function_decl
%type <MemberDeclarationSyntax*> field_decl

%type <std::vector<ArgumentSyntax*>*> argument_list
%type <ArgumentSyntax*> argument
%type <std::vector<StatementSyntax*>*> statement_list
%type <StatementSyntax*> statement
%type <StatementSyntax*> statement_block
%type <StatementSyntax*> local_decl_stmt
%type <StatementSyntax*> expr_stmt
%type <VariableDeclaratorSyntax*> var_declr;
%type <TypeSyntax*> type
%type <ExpressionSyntax*> expr
%type <ExpressionSyntax*> access_expr
%type <ExpressionSyntax*> num_lit_expr
%type <ExpressionSyntax*> assign_expr
%type <ExpressionSyntax*> bin_expr

%%

root
  : base_decl_list { $$ = new SyntaxRoot($1); driver.root = $$; }
  ;

base_decl_list
  : { $$ = new vector<MemberDeclarationSyntax*>(); }
  | base_decl_list base_decl { $$ = $1; $$->push_back($2); }
  ;

base_decl
  : namespace_decl { $$ = $1; }
  | class_decl { $$ = $1; }
  ;

namespace_decl
  : _NAMESPACE name _LCURLY base_decl_list _RCURLY { $$ = new NamespaceDeclaration($2, $4); }
  ;

class_decl
  : visibility_mod static_mod _CLASS simple_name _LCURLY member_decl_list _RCURLY
  { $$ = new ClassDeclaration($1, $2, $4, $6); }
  ;

visibility_mod
  : { $$ = new VisibilityModifierSyntax(Tots::Language::TypeVisibility::Internal); }
  | _INTERNAL { $$ = new VisibilityModifierSyntax(Tots::Language::TypeVisibility::Internal); }
  | _PRIVATE { $$ = new VisibilityModifierSyntax(Tots::Language::TypeVisibility::Private); }
  | _PROTECTED { $$ = new VisibilityModifierSyntax(Tots::Language::TypeVisibility::Protected); }
  | _PUBLIC { $$ = new VisibilityModifierSyntax(Tots::Language::TypeVisibility::Public); }
  ;

static_mod
  : { $$ = nullptr; }
  | _STATIC { $$ = new StaticModifierSyntax(); }
  ;

member_decl_list
  : { $$ = new vector<MemberDeclarationSyntax*>(); }
  | member_decl_list member_decl { $$ = $1; $$->push_back($2); }
  ;

member_decl
  : function_decl { $$ = $1;}
  | field_decl { $$ = $1; }
  | class_decl { $$ = $1; }
  ;

function_decl
  : visibility_mod static_mod type simple_name _LPAREN argument_list _RPAREN _LCURLY statement_list _RCURLY
  { $$ = new FunctionDeclaration($1, $2, $3, $4, $6, $9); }
  ;

field_decl
  : visibility_mod static_mod type simple_name _SEMICOLON
  { $$ = new FieldDeclaration($1, $2, $3, $4); }
  ;

argument_list
  : { $$ = new vector<ArgumentSyntax*>(); }
  | argument { $$ = new vector<ArgumentSyntax*>(); $$->push_back($1); }
  | argument_list _COMMA argument { $$ = $1; $$->push_back($3); }
  ;

argument
  : type var_declr { $$ = new ArgumentSyntax($1, $2); }
  ;

statement_list
  : { $$ = new vector<StatementSyntax*>(); }
  | statement_list statement { $$ = $1; $$->push_back($2); }
  ;

statement
  : statement_block { $$ = $1; }
  | local_decl_stmt { $$ = $1; }
  | expr_stmt { $$ = $1; }
  ;

statement_block
  : _LCURLY statement_list _RCURLY { $$ = new StatementBlock($2); }
  ;

local_decl_stmt
  : type var_declr _SEMICOLON { $$ = new LocalDeclarationStatement($1, $2); }
  ;

expr_stmt
  : expr _SEMICOLON { $$ = new ExpressionStatement($1); }
  ;

expr
  : simple_name { $$ = $1; }
  | access_expr { $$ = $1; }
  | num_lit_expr { $$ = $1; }
  | assign_expr { $$ = $1; }
  | bin_expr { $$ = $1; }
  ;

access_expr
  : expr _DOT simple_name { $$ = new MemberAccessExpression($1, $3); }
  ;

num_lit_expr
  : _INT_LITERAL { $$ = new NumericLiteralExpression($1); }
  ;

assign_expr
  : expr _EQ expr { $$ = new AssignmentExpression($1, $3); }
  | expr _ADD_EQ expr { $$ = new OperatorAssignExpression($1, $3, Tots::Language::Operators::Add); }
  | expr _SUB_EQ expr { $$ = new OperatorAssignExpression($1, $3, Tots::Language::Operators::Sub); }
  | expr _MUL_EQ expr { $$ = new OperatorAssignExpression($1, $3, Tots::Language::Operators::Mul); }
  | expr _DIV_EQ expr { $$ = new OperatorAssignExpression($1, $3, Tots::Language::Operators::Div); }
  ;

bin_expr
  : expr _ADD expr { $$ = new BinaryOperatorExpression($1, $3, Tots::Language::Operators::Add); }
  | expr _SUB expr { $$ = new BinaryOperatorExpression($1, $3, Tots::Language::Operators::Sub); }
  | expr _MUL expr { $$ = new BinaryOperatorExpression($1, $3, Tots::Language::Operators::Mul); }
  | expr _DIV expr { $$ = new BinaryOperatorExpression($1, $3, Tots::Language::Operators::Div); }
  ;

var_declr
  : simple_name { $$ = new VariableDeclaratorSyntax($1); }
  | simple_name _EQ expr { $$ = new VariableDeclaratorSyntax($1, $3); }
  ;

type
  : _VAR { $$ = new ExpressionDefinedType(); }
  | _VOID { $$ = new VoidType(); }
  | _INT { $$ = new PredefinedType(Tots::Language::PredefTypes::_INT); }
  | _FLOAT { $$ = new PredefinedType(Tots::Language::PredefTypes::_FLOAT); }
  | _BOOL { $$ = new PredefinedType(Tots::Language::PredefTypes::_BOOL); }
  | _CHAR { $$ = new PredefinedType(Tots::Language::PredefTypes::_CHAR); }
  | name { $$ = $1; }
  ;

name
  : simple_name { $$ = $1; }
  | name _DOT name { $$ = new QualifiedNameSyntax($1, $3); }
  ;

simple_name
  : _ID { $$ = new IdentifierNameSyntax($1); }
  ;

%%


void TotsParser::error(const std::string &err_message )
{
	std::cerr << "Error: " << err_message << std::endl;
}
