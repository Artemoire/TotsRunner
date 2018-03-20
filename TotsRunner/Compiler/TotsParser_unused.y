%{
  #include <iostream>  
  #include <vector>  

  #include "TotsParserInterface.h"
  #include "StatementBlock.h"
  #include "LocalDeclarationStatement.h"
  #include "ExpressionStatement.h"
  #include "VariableDeclaratorSyntax.h"
  #include "NamedType.h"
  #include "ExpressionDefinedType.h"
  #include "PredefinedType.h"
  #include "AssignmentExpression.h"
  #include "IdentifierExpression.h"
  #include "NumericLiteralExpression.h"
  #include "BinaryOperatorExpression.h"
  #include "OperatorAssignExpression.h"

  using namespace std;

  SyntaxRoot * root;

extern void scan_string_prepare(char *, int);
extern void scan_string_release();

  int yyparse(void);
  int yylex(void);
  int yyerror(const char *s);
%}

%code requires {
  #include <vector>

  #include "SyntaxRoot.h"  
  #include "VariableDeclaratorSyntax.h"
  #include "SyntaxError.h"
}


%start root

%union {  
  unsigned long WRD;
  char op;
  char *id;
  std::vector<FunctionDeclarationSyntax *> *func_d_nodes;
  FunctionDeclarationSyntax *func_d_node;
  std::vector<ArgumentSyntax*> *arg_nodes;
  ArgumentSyntax * arg_node;  
  std::vector<StatementSyntax*> *stmt_nodes;  
  StatementSyntax * stmt_node;
  VariableDeclaratorSyntax * var_declr_node;
  TypeSyntax *type_i_node;
  ExpressionSyntax * expr_node;
  SyntaxRoot *root_node;
}

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
%token _DOT
%token _SEMICOLON
%right _EQ _ADD_EQ _SUB_EQ _MUL_EQ _DIV_EQ
%left _ADD _SUB
%left _MUL _DIV
%token <id> _ID
%token <WRD> _INT_LITERAL

%type <root_node> root
%type <func_d_nodes> function_decl_list
%type <func_d_node> function_decl
%type <arg_nodes> argument_list
%type <arg_node> argument
%type <stmt_nodes> statement_list
%type <stmt_node> statement
%type <stmt_node> statement_block
%type <stmt_node> local_decl_stmt
%type <stmt_node> expr_stmt
%type <var_declr_node> var_declr;
%type <type_i_node> type
%type <expr_node> expr
%type <expr_node> id_expr
%type <expr_node> num_lit_expr
%type <expr_node> assign_expr
%type <expr_node> bin_expr

%%

root
  : function_decl_list { $$ = new SyntaxRoot($1); root = $$; }
  ;

function_decl_list
  : function_decl { $$ = new vector<FunctionDeclarationSyntax*>(); $$->push_back($1); }
  | function_decl_list function_decl { $$ = $1; $$->push_back($2); }
  ;

function_decl
  : type _ID _LPAREN argument_list _RPAREN _LCURLY statement_list _RCURLY
  { $$ = new FunctionDeclarationSyntax($1, $2, $4, $7); }
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
  : id_expr { $$ = $1; }
  | num_lit_expr { $$ = $1; }
  | assign_expr { $$ = $1; }
  | bin_expr { $$ = $1; }
  ;

id_expr
  :  _ID { $$ = new IdentifierExpression($1); }
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
  :  _ID { $$ = new VariableDeclaratorSyntax($1); }
  | _ID _EQ expr { $$ = new VariableDeclaratorSyntax($1, $3); }
  ;

type
  : _VAR { $$ = new ExpressionDefinedType(); }
  | _VOID { $$ = new PredefinedType(Tots::Language::PredefTypes::_VOID); }
  | _INT { $$ = new PredefinedType(Tots::Language::PredefTypes::_INT); }
  | _FLOAT { $$ = new PredefinedType(Tots::Language::PredefTypes::_FLOAT); }
  | _BOOL { $$ = new PredefinedType(Tots::Language::PredefTypes::_BOOL); }
  | _CHAR { $$ = new PredefinedType(Tots::Language::PredefTypes::_CHAR); }
  | _ID { $$ = new NamedType($1); }
  ;

%%


int yyerror(const char *s) {
  cout << endl << "ERROR: "<< s << endl;
  return 0;
}

SyntaxRoot * Tots::Language::Parser::parse(char * tstr, int size)
{
// note yy_scan_buffer is is looking for a double null string
	scan_string_prepare(tstr, size);
	//YY_BUFFER_STATE buffer = yy_scan_buffer(tstr, size);
	yyparse();

	int errors_count = SyntaxError::errors->size();

	for(int i = 0; i < errors_count; ++i)
		cout << (*SyntaxError::errors)[i]->msg << endl;
	
	//yy_delete_buffer(buffer);	
	scan_string_release();

	if (errors_count > 0)
	{
		// todo delete root
		return nullptr;
	}

	return root;
}