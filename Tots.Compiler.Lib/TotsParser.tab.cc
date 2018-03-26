// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "TotsParser.tab.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "TotsParser.tab.hh"

// User implementation prologue.

#line 51 "TotsParser.tab.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 51 "TotsParser.yy" // lalr1.cc:413

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

#line 78 "TotsParser.tab.cc" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 4 "TotsParser.yy" // lalr1.cc:479
namespace Tots { namespace Language { namespace Syntax { namespace Parser {
#line 145 "TotsParser.tab.cc" // lalr1.cc:479

  /// Build a parser object.
  TotsParser::TotsParser (TotsScanner  &scanner_yyarg, TotsParserDriver  &driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

  TotsParser::~TotsParser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  TotsParser::syntax_error::syntax_error (const std::string& m)
    : std::runtime_error (m)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  TotsParser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  TotsParser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
  {
      switch (other.type_get ())
    {
      case 47: // argument
        value.copy< ArgumentSyntax* > (other.value);
        break;

      case 53: // expr
      case 54: // access_expr
      case 55: // num_lit_expr
      case 56: // assign_expr
      case 57: // bin_expr
        value.copy< ExpressionSyntax* > (other.value);
        break;

      case 37: // base_decl
      case 38: // namespace_decl
      case 39: // class_decl
      case 43: // member_decl
      case 44: // function_decl
      case 45: // field_decl
        value.copy< MemberDeclarationSyntax* > (other.value);
        break;

      case 60: // name
        value.copy< NameSyntax* > (other.value);
        break;

      case 61: // simple_name
        value.copy< SimpleNameSyntax* > (other.value);
        break;

      case 49: // statement
      case 50: // statement_block
      case 51: // local_decl_stmt
      case 52: // expr_stmt
        value.copy< StatementSyntax* > (other.value);
        break;

      case 41: // static_mod
        value.copy< StaticModifierSyntax* > (other.value);
        break;

      case 35: // root
        value.copy< SyntaxRoot* > (other.value);
        break;

      case 59: // type
        value.copy< TypeSyntax* > (other.value);
        break;

      case 58: // var_declr
        value.copy< VariableDeclaratorSyntax* > (other.value);
        break;

      case 40: // visibility_mod
        value.copy< VisibilityModifierSyntax* > (other.value);
        break;

      case 32: // _ID
        value.copy< std::string > (other.value);
        break;

      case 46: // argument_list
        value.copy< std::vector<ArgumentSyntax*>* > (other.value);
        break;

      case 36: // base_decl_list
      case 42: // member_decl_list
        value.copy< std::vector<MemberDeclarationSyntax*>* > (other.value);
        break;

      case 48: // statement_list
        value.copy< std::vector<StatementSyntax*>* > (other.value);
        break;

      case 33: // _INT_LITERAL
        value.copy< unsigned long > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
  TotsParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v)
    : Base (t)
    , value ()
  {
    (void) v;
      switch (this->type_get ())
    {
      case 47: // argument
        value.copy< ArgumentSyntax* > (v);
        break;

      case 53: // expr
      case 54: // access_expr
      case 55: // num_lit_expr
      case 56: // assign_expr
      case 57: // bin_expr
        value.copy< ExpressionSyntax* > (v);
        break;

      case 37: // base_decl
      case 38: // namespace_decl
      case 39: // class_decl
      case 43: // member_decl
      case 44: // function_decl
      case 45: // field_decl
        value.copy< MemberDeclarationSyntax* > (v);
        break;

      case 60: // name
        value.copy< NameSyntax* > (v);
        break;

      case 61: // simple_name
        value.copy< SimpleNameSyntax* > (v);
        break;

      case 49: // statement
      case 50: // statement_block
      case 51: // local_decl_stmt
      case 52: // expr_stmt
        value.copy< StatementSyntax* > (v);
        break;

      case 41: // static_mod
        value.copy< StaticModifierSyntax* > (v);
        break;

      case 35: // root
        value.copy< SyntaxRoot* > (v);
        break;

      case 59: // type
        value.copy< TypeSyntax* > (v);
        break;

      case 58: // var_declr
        value.copy< VariableDeclaratorSyntax* > (v);
        break;

      case 40: // visibility_mod
        value.copy< VisibilityModifierSyntax* > (v);
        break;

      case 32: // _ID
        value.copy< std::string > (v);
        break;

      case 46: // argument_list
        value.copy< std::vector<ArgumentSyntax*>* > (v);
        break;

      case 36: // base_decl_list
      case 42: // member_decl_list
        value.copy< std::vector<MemberDeclarationSyntax*>* > (v);
        break;

      case 48: // statement_list
        value.copy< std::vector<StatementSyntax*>* > (v);
        break;

      case 33: // _INT_LITERAL
        value.copy< unsigned long > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
  TotsParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  TotsParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ArgumentSyntax* v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
  TotsParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ExpressionSyntax* v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
  TotsParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const MemberDeclarationSyntax* v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
  TotsParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const NameSyntax* v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
  TotsParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const SimpleNameSyntax* v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
  TotsParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const StatementSyntax* v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
  TotsParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const StaticModifierSyntax* v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
  TotsParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const SyntaxRoot* v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
  TotsParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const TypeSyntax* v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
  TotsParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const VariableDeclaratorSyntax* v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
  TotsParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const VisibilityModifierSyntax* v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
  TotsParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::string v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
  TotsParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::vector<ArgumentSyntax*>* v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
  TotsParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::vector<MemberDeclarationSyntax*>* v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
  TotsParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::vector<StatementSyntax*>* v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
  TotsParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const unsigned long v)
    : Base (t)
    , value (v)
  {}


  template <typename Base>
  inline
  TotsParser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  TotsParser::basic_symbol<Base>::clear ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    basic_symbol<Base>& yysym = *this;
    (void) yysym;
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
    {
      case 47: // argument
        value.template destroy< ArgumentSyntax* > ();
        break;

      case 53: // expr
      case 54: // access_expr
      case 55: // num_lit_expr
      case 56: // assign_expr
      case 57: // bin_expr
        value.template destroy< ExpressionSyntax* > ();
        break;

      case 37: // base_decl
      case 38: // namespace_decl
      case 39: // class_decl
      case 43: // member_decl
      case 44: // function_decl
      case 45: // field_decl
        value.template destroy< MemberDeclarationSyntax* > ();
        break;

      case 60: // name
        value.template destroy< NameSyntax* > ();
        break;

      case 61: // simple_name
        value.template destroy< SimpleNameSyntax* > ();
        break;

      case 49: // statement
      case 50: // statement_block
      case 51: // local_decl_stmt
      case 52: // expr_stmt
        value.template destroy< StatementSyntax* > ();
        break;

      case 41: // static_mod
        value.template destroy< StaticModifierSyntax* > ();
        break;

      case 35: // root
        value.template destroy< SyntaxRoot* > ();
        break;

      case 59: // type
        value.template destroy< TypeSyntax* > ();
        break;

      case 58: // var_declr
        value.template destroy< VariableDeclaratorSyntax* > ();
        break;

      case 40: // visibility_mod
        value.template destroy< VisibilityModifierSyntax* > ();
        break;

      case 32: // _ID
        value.template destroy< std::string > ();
        break;

      case 46: // argument_list
        value.template destroy< std::vector<ArgumentSyntax*>* > ();
        break;

      case 36: // base_decl_list
      case 42: // member_decl_list
        value.template destroy< std::vector<MemberDeclarationSyntax*>* > ();
        break;

      case 48: // statement_list
        value.template destroy< std::vector<StatementSyntax*>* > ();
        break;

      case 33: // _INT_LITERAL
        value.template destroy< unsigned long > ();
        break;

      default:
        break;
    }

    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  TotsParser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  TotsParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      case 47: // argument
        value.move< ArgumentSyntax* > (s.value);
        break;

      case 53: // expr
      case 54: // access_expr
      case 55: // num_lit_expr
      case 56: // assign_expr
      case 57: // bin_expr
        value.move< ExpressionSyntax* > (s.value);
        break;

      case 37: // base_decl
      case 38: // namespace_decl
      case 39: // class_decl
      case 43: // member_decl
      case 44: // function_decl
      case 45: // field_decl
        value.move< MemberDeclarationSyntax* > (s.value);
        break;

      case 60: // name
        value.move< NameSyntax* > (s.value);
        break;

      case 61: // simple_name
        value.move< SimpleNameSyntax* > (s.value);
        break;

      case 49: // statement
      case 50: // statement_block
      case 51: // local_decl_stmt
      case 52: // expr_stmt
        value.move< StatementSyntax* > (s.value);
        break;

      case 41: // static_mod
        value.move< StaticModifierSyntax* > (s.value);
        break;

      case 35: // root
        value.move< SyntaxRoot* > (s.value);
        break;

      case 59: // type
        value.move< TypeSyntax* > (s.value);
        break;

      case 58: // var_declr
        value.move< VariableDeclaratorSyntax* > (s.value);
        break;

      case 40: // visibility_mod
        value.move< VisibilityModifierSyntax* > (s.value);
        break;

      case 32: // _ID
        value.move< std::string > (s.value);
        break;

      case 46: // argument_list
        value.move< std::vector<ArgumentSyntax*>* > (s.value);
        break;

      case 36: // base_decl_list
      case 42: // member_decl_list
        value.move< std::vector<MemberDeclarationSyntax*>* > (s.value);
        break;

      case 48: // statement_list
        value.move< std::vector<StatementSyntax*>* > (s.value);
        break;

      case 33: // _INT_LITERAL
        value.move< unsigned long > (s.value);
        break;

      default:
        break;
    }

  }

  // by_type.
  inline
  TotsParser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  TotsParser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  TotsParser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  TotsParser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  TotsParser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  TotsParser::by_type::type_get () const
  {
    return type;
  }
  // Implementation of make_symbol for each symbol type.
  TotsParser::symbol_type
  TotsParser::make__NAMESPACE ()
  {
    return symbol_type (token::_NAMESPACE);
  }

  TotsParser::symbol_type
  TotsParser::make__CLASS ()
  {
    return symbol_type (token::_CLASS);
  }

  TotsParser::symbol_type
  TotsParser::make__INTERNAL ()
  {
    return symbol_type (token::_INTERNAL);
  }

  TotsParser::symbol_type
  TotsParser::make__PRIVATE ()
  {
    return symbol_type (token::_PRIVATE);
  }

  TotsParser::symbol_type
  TotsParser::make__PROTECTED ()
  {
    return symbol_type (token::_PROTECTED);
  }

  TotsParser::symbol_type
  TotsParser::make__PUBLIC ()
  {
    return symbol_type (token::_PUBLIC);
  }

  TotsParser::symbol_type
  TotsParser::make__STATIC ()
  {
    return symbol_type (token::_STATIC);
  }

  TotsParser::symbol_type
  TotsParser::make__VAR ()
  {
    return symbol_type (token::_VAR);
  }

  TotsParser::symbol_type
  TotsParser::make__VOID ()
  {
    return symbol_type (token::_VOID);
  }

  TotsParser::symbol_type
  TotsParser::make__INT ()
  {
    return symbol_type (token::_INT);
  }

  TotsParser::symbol_type
  TotsParser::make__FLOAT ()
  {
    return symbol_type (token::_FLOAT);
  }

  TotsParser::symbol_type
  TotsParser::make__BOOL ()
  {
    return symbol_type (token::_BOOL);
  }

  TotsParser::symbol_type
  TotsParser::make__CHAR ()
  {
    return symbol_type (token::_CHAR);
  }

  TotsParser::symbol_type
  TotsParser::make__LPAREN ()
  {
    return symbol_type (token::_LPAREN);
  }

  TotsParser::symbol_type
  TotsParser::make__RPAREN ()
  {
    return symbol_type (token::_RPAREN);
  }

  TotsParser::symbol_type
  TotsParser::make__LCURLY ()
  {
    return symbol_type (token::_LCURLY);
  }

  TotsParser::symbol_type
  TotsParser::make__RCURLY ()
  {
    return symbol_type (token::_RCURLY);
  }

  TotsParser::symbol_type
  TotsParser::make__COMMA ()
  {
    return symbol_type (token::_COMMA);
  }

  TotsParser::symbol_type
  TotsParser::make__DOT ()
  {
    return symbol_type (token::_DOT);
  }

  TotsParser::symbol_type
  TotsParser::make__SEMICOLON ()
  {
    return symbol_type (token::_SEMICOLON);
  }

  TotsParser::symbol_type
  TotsParser::make__EQ ()
  {
    return symbol_type (token::_EQ);
  }

  TotsParser::symbol_type
  TotsParser::make__ADD_EQ ()
  {
    return symbol_type (token::_ADD_EQ);
  }

  TotsParser::symbol_type
  TotsParser::make__SUB_EQ ()
  {
    return symbol_type (token::_SUB_EQ);
  }

  TotsParser::symbol_type
  TotsParser::make__MUL_EQ ()
  {
    return symbol_type (token::_MUL_EQ);
  }

  TotsParser::symbol_type
  TotsParser::make__DIV_EQ ()
  {
    return symbol_type (token::_DIV_EQ);
  }

  TotsParser::symbol_type
  TotsParser::make__ADD ()
  {
    return symbol_type (token::_ADD);
  }

  TotsParser::symbol_type
  TotsParser::make__SUB ()
  {
    return symbol_type (token::_SUB);
  }

  TotsParser::symbol_type
  TotsParser::make__MUL ()
  {
    return symbol_type (token::_MUL);
  }

  TotsParser::symbol_type
  TotsParser::make__DIV ()
  {
    return symbol_type (token::_DIV);
  }

  TotsParser::symbol_type
  TotsParser::make__ID (const std::string& v)
  {
    return symbol_type (token::_ID, v);
  }

  TotsParser::symbol_type
  TotsParser::make__INT_LITERAL (const unsigned long& v)
  {
    return symbol_type (token::_INT_LITERAL, v);
  }



  // by_state.
  inline
  TotsParser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  TotsParser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  TotsParser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  TotsParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  TotsParser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  TotsParser::symbol_number_type
  TotsParser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  TotsParser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  TotsParser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s)
  {
      switch (that.type_get ())
    {
      case 47: // argument
        value.move< ArgumentSyntax* > (that.value);
        break;

      case 53: // expr
      case 54: // access_expr
      case 55: // num_lit_expr
      case 56: // assign_expr
      case 57: // bin_expr
        value.move< ExpressionSyntax* > (that.value);
        break;

      case 37: // base_decl
      case 38: // namespace_decl
      case 39: // class_decl
      case 43: // member_decl
      case 44: // function_decl
      case 45: // field_decl
        value.move< MemberDeclarationSyntax* > (that.value);
        break;

      case 60: // name
        value.move< NameSyntax* > (that.value);
        break;

      case 61: // simple_name
        value.move< SimpleNameSyntax* > (that.value);
        break;

      case 49: // statement
      case 50: // statement_block
      case 51: // local_decl_stmt
      case 52: // expr_stmt
        value.move< StatementSyntax* > (that.value);
        break;

      case 41: // static_mod
        value.move< StaticModifierSyntax* > (that.value);
        break;

      case 35: // root
        value.move< SyntaxRoot* > (that.value);
        break;

      case 59: // type
        value.move< TypeSyntax* > (that.value);
        break;

      case 58: // var_declr
        value.move< VariableDeclaratorSyntax* > (that.value);
        break;

      case 40: // visibility_mod
        value.move< VisibilityModifierSyntax* > (that.value);
        break;

      case 32: // _ID
        value.move< std::string > (that.value);
        break;

      case 46: // argument_list
        value.move< std::vector<ArgumentSyntax*>* > (that.value);
        break;

      case 36: // base_decl_list
      case 42: // member_decl_list
        value.move< std::vector<MemberDeclarationSyntax*>* > (that.value);
        break;

      case 48: // statement_list
        value.move< std::vector<StatementSyntax*>* > (that.value);
        break;

      case 33: // _INT_LITERAL
        value.move< unsigned long > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  TotsParser::stack_symbol_type&
  TotsParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 47: // argument
        value.copy< ArgumentSyntax* > (that.value);
        break;

      case 53: // expr
      case 54: // access_expr
      case 55: // num_lit_expr
      case 56: // assign_expr
      case 57: // bin_expr
        value.copy< ExpressionSyntax* > (that.value);
        break;

      case 37: // base_decl
      case 38: // namespace_decl
      case 39: // class_decl
      case 43: // member_decl
      case 44: // function_decl
      case 45: // field_decl
        value.copy< MemberDeclarationSyntax* > (that.value);
        break;

      case 60: // name
        value.copy< NameSyntax* > (that.value);
        break;

      case 61: // simple_name
        value.copy< SimpleNameSyntax* > (that.value);
        break;

      case 49: // statement
      case 50: // statement_block
      case 51: // local_decl_stmt
      case 52: // expr_stmt
        value.copy< StatementSyntax* > (that.value);
        break;

      case 41: // static_mod
        value.copy< StaticModifierSyntax* > (that.value);
        break;

      case 35: // root
        value.copy< SyntaxRoot* > (that.value);
        break;

      case 59: // type
        value.copy< TypeSyntax* > (that.value);
        break;

      case 58: // var_declr
        value.copy< VariableDeclaratorSyntax* > (that.value);
        break;

      case 40: // visibility_mod
        value.copy< VisibilityModifierSyntax* > (that.value);
        break;

      case 32: // _ID
        value.copy< std::string > (that.value);
        break;

      case 46: // argument_list
        value.copy< std::vector<ArgumentSyntax*>* > (that.value);
        break;

      case 36: // base_decl_list
      case 42: // member_decl_list
        value.copy< std::vector<MemberDeclarationSyntax*>* > (that.value);
        break;

      case 48: // statement_list
        value.copy< std::vector<StatementSyntax*>* > (that.value);
        break;

      case 33: // _INT_LITERAL
        value.copy< unsigned long > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }


  template <typename Base>
  inline
  void
  TotsParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  TotsParser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  TotsParser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  TotsParser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  TotsParser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  TotsParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  TotsParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  TotsParser::debug_level_type
  TotsParser::debug_level () const
  {
    return yydebug_;
  }

  void
  TotsParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline TotsParser::state_type
  TotsParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  TotsParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  TotsParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  TotsParser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 47: // argument
        yylhs.value.build< ArgumentSyntax* > ();
        break;

      case 53: // expr
      case 54: // access_expr
      case 55: // num_lit_expr
      case 56: // assign_expr
      case 57: // bin_expr
        yylhs.value.build< ExpressionSyntax* > ();
        break;

      case 37: // base_decl
      case 38: // namespace_decl
      case 39: // class_decl
      case 43: // member_decl
      case 44: // function_decl
      case 45: // field_decl
        yylhs.value.build< MemberDeclarationSyntax* > ();
        break;

      case 60: // name
        yylhs.value.build< NameSyntax* > ();
        break;

      case 61: // simple_name
        yylhs.value.build< SimpleNameSyntax* > ();
        break;

      case 49: // statement
      case 50: // statement_block
      case 51: // local_decl_stmt
      case 52: // expr_stmt
        yylhs.value.build< StatementSyntax* > ();
        break;

      case 41: // static_mod
        yylhs.value.build< StaticModifierSyntax* > ();
        break;

      case 35: // root
        yylhs.value.build< SyntaxRoot* > ();
        break;

      case 59: // type
        yylhs.value.build< TypeSyntax* > ();
        break;

      case 58: // var_declr
        yylhs.value.build< VariableDeclaratorSyntax* > ();
        break;

      case 40: // visibility_mod
        yylhs.value.build< VisibilityModifierSyntax* > ();
        break;

      case 32: // _ID
        yylhs.value.build< std::string > ();
        break;

      case 46: // argument_list
        yylhs.value.build< std::vector<ArgumentSyntax*>* > ();
        break;

      case 36: // base_decl_list
      case 42: // member_decl_list
        yylhs.value.build< std::vector<MemberDeclarationSyntax*>* > ();
        break;

      case 48: // statement_list
        yylhs.value.build< std::vector<StatementSyntax*>* > ();
        break;

      case 33: // _INT_LITERAL
        yylhs.value.build< unsigned long > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 147 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< SyntaxRoot* > () = new SyntaxRoot(yystack_[0].value.as< std::vector<MemberDeclarationSyntax*>* > ()); driver.root = yylhs.value.as< SyntaxRoot* > (); }
#line 1436 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 151 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< std::vector<MemberDeclarationSyntax*>* > () = new vector<MemberDeclarationSyntax*>(); }
#line 1442 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 152 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< std::vector<MemberDeclarationSyntax*>* > () = yystack_[1].value.as< std::vector<MemberDeclarationSyntax*>* > (); yylhs.value.as< std::vector<MemberDeclarationSyntax*>* > ()->push_back(yystack_[0].value.as< MemberDeclarationSyntax* > ()); }
#line 1448 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 156 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< MemberDeclarationSyntax* > () = yystack_[0].value.as< MemberDeclarationSyntax* > (); }
#line 1454 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 157 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< MemberDeclarationSyntax* > () = yystack_[0].value.as< MemberDeclarationSyntax* > (); }
#line 1460 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 161 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< MemberDeclarationSyntax* > () = new NamespaceDeclaration(yystack_[3].value.as< NameSyntax* > (), yystack_[1].value.as< std::vector<MemberDeclarationSyntax*>* > ()); }
#line 1466 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 166 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< MemberDeclarationSyntax* > () = new ClassDeclaration(yystack_[6].value.as< VisibilityModifierSyntax* > (), yystack_[5].value.as< StaticModifierSyntax* > (), yystack_[3].value.as< SimpleNameSyntax* > (), yystack_[1].value.as< std::vector<MemberDeclarationSyntax*>* > ()); }
#line 1472 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 170 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< VisibilityModifierSyntax* > () = new VisibilityModifierSyntax(Tots::Language::TypeVisibility::Internal); }
#line 1478 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 171 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< VisibilityModifierSyntax* > () = new VisibilityModifierSyntax(Tots::Language::TypeVisibility::Internal); }
#line 1484 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 172 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< VisibilityModifierSyntax* > () = new VisibilityModifierSyntax(Tots::Language::TypeVisibility::Private); }
#line 1490 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 173 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< VisibilityModifierSyntax* > () = new VisibilityModifierSyntax(Tots::Language::TypeVisibility::Protected); }
#line 1496 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 174 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< VisibilityModifierSyntax* > () = new VisibilityModifierSyntax(Tots::Language::TypeVisibility::Public); }
#line 1502 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 178 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< StaticModifierSyntax* > () = nullptr; }
#line 1508 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 179 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< StaticModifierSyntax* > () = new StaticModifierSyntax(); }
#line 1514 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 183 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< std::vector<MemberDeclarationSyntax*>* > () = new vector<MemberDeclarationSyntax*>(); }
#line 1520 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 184 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< std::vector<MemberDeclarationSyntax*>* > () = yystack_[1].value.as< std::vector<MemberDeclarationSyntax*>* > (); yylhs.value.as< std::vector<MemberDeclarationSyntax*>* > ()->push_back(yystack_[0].value.as< MemberDeclarationSyntax* > ()); }
#line 1526 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 188 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< MemberDeclarationSyntax* > () = yystack_[0].value.as< MemberDeclarationSyntax* > ();}
#line 1532 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 189 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< MemberDeclarationSyntax* > () = yystack_[0].value.as< MemberDeclarationSyntax* > (); }
#line 1538 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 190 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< MemberDeclarationSyntax* > () = yystack_[0].value.as< MemberDeclarationSyntax* > (); }
#line 1544 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 195 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< MemberDeclarationSyntax* > () = new FunctionDeclaration(yystack_[9].value.as< VisibilityModifierSyntax* > (), yystack_[8].value.as< StaticModifierSyntax* > (), yystack_[7].value.as< TypeSyntax* > (), yystack_[6].value.as< SimpleNameSyntax* > (), yystack_[4].value.as< std::vector<ArgumentSyntax*>* > (), yystack_[1].value.as< std::vector<StatementSyntax*>* > ()); }
#line 1550 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 200 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< MemberDeclarationSyntax* > () = new FieldDeclaration(yystack_[4].value.as< VisibilityModifierSyntax* > (), yystack_[3].value.as< StaticModifierSyntax* > (), yystack_[2].value.as< TypeSyntax* > (), yystack_[1].value.as< SimpleNameSyntax* > ()); }
#line 1556 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 204 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< std::vector<ArgumentSyntax*>* > () = new vector<ArgumentSyntax*>(); }
#line 1562 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 205 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< std::vector<ArgumentSyntax*>* > () = new vector<ArgumentSyntax*>(); yylhs.value.as< std::vector<ArgumentSyntax*>* > ()->push_back(yystack_[0].value.as< ArgumentSyntax* > ()); }
#line 1568 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 206 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< std::vector<ArgumentSyntax*>* > () = yystack_[2].value.as< std::vector<ArgumentSyntax*>* > (); yylhs.value.as< std::vector<ArgumentSyntax*>* > ()->push_back(yystack_[0].value.as< ArgumentSyntax* > ()); }
#line 1574 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 210 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< ArgumentSyntax* > () = new ArgumentSyntax(yystack_[1].value.as< TypeSyntax* > (), yystack_[0].value.as< VariableDeclaratorSyntax* > ()); }
#line 1580 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 214 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< std::vector<StatementSyntax*>* > () = new vector<StatementSyntax*>(); }
#line 1586 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 215 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< std::vector<StatementSyntax*>* > () = yystack_[1].value.as< std::vector<StatementSyntax*>* > (); yylhs.value.as< std::vector<StatementSyntax*>* > ()->push_back(yystack_[0].value.as< StatementSyntax* > ()); }
#line 1592 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 219 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< StatementSyntax* > () = yystack_[0].value.as< StatementSyntax* > (); }
#line 1598 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 220 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< StatementSyntax* > () = yystack_[0].value.as< StatementSyntax* > (); }
#line 1604 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 221 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< StatementSyntax* > () = yystack_[0].value.as< StatementSyntax* > (); }
#line 1610 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 225 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< StatementSyntax* > () = new StatementBlock(yystack_[1].value.as< std::vector<StatementSyntax*>* > ()); }
#line 1616 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 229 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< StatementSyntax* > () = new LocalDeclarationStatement(yystack_[2].value.as< TypeSyntax* > (), yystack_[1].value.as< VariableDeclaratorSyntax* > ()); }
#line 1622 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 233 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< StatementSyntax* > () = new ExpressionStatement(yystack_[1].value.as< ExpressionSyntax* > ()); }
#line 1628 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 237 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< ExpressionSyntax* > () = yystack_[0].value.as< SimpleNameSyntax* > (); }
#line 1634 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 238 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< ExpressionSyntax* > () = yystack_[0].value.as< ExpressionSyntax* > (); }
#line 1640 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 239 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< ExpressionSyntax* > () = yystack_[0].value.as< ExpressionSyntax* > (); }
#line 1646 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 240 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< ExpressionSyntax* > () = yystack_[0].value.as< ExpressionSyntax* > (); }
#line 1652 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 241 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< ExpressionSyntax* > () = yystack_[0].value.as< ExpressionSyntax* > (); }
#line 1658 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 245 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< ExpressionSyntax* > () = new MemberAccessExpression(yystack_[2].value.as< ExpressionSyntax* > (), yystack_[0].value.as< SimpleNameSyntax* > ()); }
#line 1664 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 249 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< ExpressionSyntax* > () = new NumericLiteralExpression(yystack_[0].value.as< unsigned long > ()); }
#line 1670 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 253 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< ExpressionSyntax* > () = new AssignmentExpression(yystack_[2].value.as< ExpressionSyntax* > (), yystack_[0].value.as< ExpressionSyntax* > ()); }
#line 1676 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 43:
#line 254 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< ExpressionSyntax* > () = new OperatorAssignExpression(yystack_[2].value.as< ExpressionSyntax* > (), yystack_[0].value.as< ExpressionSyntax* > (), Tots::Language::Operators::Add); }
#line 1682 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 44:
#line 255 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< ExpressionSyntax* > () = new OperatorAssignExpression(yystack_[2].value.as< ExpressionSyntax* > (), yystack_[0].value.as< ExpressionSyntax* > (), Tots::Language::Operators::Sub); }
#line 1688 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 45:
#line 256 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< ExpressionSyntax* > () = new OperatorAssignExpression(yystack_[2].value.as< ExpressionSyntax* > (), yystack_[0].value.as< ExpressionSyntax* > (), Tots::Language::Operators::Mul); }
#line 1694 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 46:
#line 257 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< ExpressionSyntax* > () = new OperatorAssignExpression(yystack_[2].value.as< ExpressionSyntax* > (), yystack_[0].value.as< ExpressionSyntax* > (), Tots::Language::Operators::Div); }
#line 1700 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 47:
#line 261 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< ExpressionSyntax* > () = new BinaryOperatorExpression(yystack_[2].value.as< ExpressionSyntax* > (), yystack_[0].value.as< ExpressionSyntax* > (), Tots::Language::Operators::Add); }
#line 1706 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 48:
#line 262 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< ExpressionSyntax* > () = new BinaryOperatorExpression(yystack_[2].value.as< ExpressionSyntax* > (), yystack_[0].value.as< ExpressionSyntax* > (), Tots::Language::Operators::Sub); }
#line 1712 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 49:
#line 263 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< ExpressionSyntax* > () = new BinaryOperatorExpression(yystack_[2].value.as< ExpressionSyntax* > (), yystack_[0].value.as< ExpressionSyntax* > (), Tots::Language::Operators::Mul); }
#line 1718 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 50:
#line 264 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< ExpressionSyntax* > () = new BinaryOperatorExpression(yystack_[2].value.as< ExpressionSyntax* > (), yystack_[0].value.as< ExpressionSyntax* > (), Tots::Language::Operators::Div); }
#line 1724 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 51:
#line 268 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< VariableDeclaratorSyntax* > () = new VariableDeclaratorSyntax(yystack_[0].value.as< SimpleNameSyntax* > ()); }
#line 1730 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 52:
#line 269 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< VariableDeclaratorSyntax* > () = new VariableDeclaratorSyntax(yystack_[2].value.as< SimpleNameSyntax* > (), yystack_[0].value.as< ExpressionSyntax* > ()); }
#line 1736 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 53:
#line 273 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< TypeSyntax* > () = new ExpressionDefinedType(); }
#line 1742 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 54:
#line 274 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< TypeSyntax* > () = new VoidType(); }
#line 1748 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 55:
#line 275 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< TypeSyntax* > () = new PredefinedType(Tots::Language::PredefTypes::_INT); }
#line 1754 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 56:
#line 276 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< TypeSyntax* > () = new PredefinedType(Tots::Language::PredefTypes::_FLOAT); }
#line 1760 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 57:
#line 277 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< TypeSyntax* > () = new PredefinedType(Tots::Language::PredefTypes::_BOOL); }
#line 1766 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 58:
#line 278 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< TypeSyntax* > () = new PredefinedType(Tots::Language::PredefTypes::_CHAR); }
#line 1772 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 59:
#line 279 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< TypeSyntax* > () = yystack_[0].value.as< NameSyntax* > (); }
#line 1778 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 60:
#line 283 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< NameSyntax* > () = yystack_[0].value.as< SimpleNameSyntax* > (); }
#line 1784 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 61:
#line 284 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< NameSyntax* > () = new QualifiedNameSyntax(yystack_[2].value.as< NameSyntax* > (), yystack_[0].value.as< NameSyntax* > ()); }
#line 1790 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 62:
#line 288 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< SimpleNameSyntax* > () = new IdentifierNameSyntax(yystack_[0].value.as< std::string > ()); }
#line 1796 "TotsParser.tab.cc" // lalr1.cc:859
    break;


#line 1800 "TotsParser.tab.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  TotsParser::error (const syntax_error& yyexc)
  {
    error (yyexc.what());
  }

  // Generate an error message.
  std::string
  TotsParser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char TotsParser::yypact_ninf_ = -33;

  const signed char TotsParser::yytable_ninf_ = -61;

  const signed char
  TotsParser::yypact_[] =
  {
     -33,    21,    41,   -33,     0,   -33,   -33,   -33,   -33,   -33,
     -33,   -33,    22,   -33,   -14,   -33,   -33,    31,   -33,     0,
       0,    19,   -33,    24,   -33,   -33,   100,   -33,   -33,    22,
     -33,   -33,   -33,    -2,   -33,   -33,   -33,   -33,   -33,   -33,
       0,    16,    12,    85,   -33,    -3,   -33,     0,    43,    85,
     -33,    17,   -33,   -33,   -27,    61,   -33,   110,   -33,   -33,
     -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,    99,
       0,    30,     0,   -27,   -27,   -27,   -27,   -27,   -27,   -27,
     -27,   -27,    71,   -33,    42,   -33,   119,   119,   119,   119,
     119,   -11,   -11,   -33,   -33,   -33,   -33
  };

  const unsigned char
  TotsParser::yydefact_[] =
  {
       3,     0,     9,     1,     0,    10,    11,    12,    13,     4,
       5,     6,    14,    62,     0,    60,    15,     0,     3,     0,
       0,     9,    61,     0,     7,    16,     9,     8,    20,    14,
      17,    18,    19,     0,    53,    54,    55,    56,    57,    58,
       0,    59,     0,    23,    22,     0,    24,     0,     0,     0,
      26,    51,    27,    25,     0,     0,    41,    52,    36,    37,
      38,    39,    35,    27,    21,    28,    29,    30,    31,     0,
       0,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,     0,    40,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    32,    33
  };

  const signed char
  TotsParser::yypgoto_[] =
  {
     -33,   -33,    45,   -33,   -33,    39,    44,    38,   -33,   -33,
     -33,   -33,   -33,    20,    14,   -33,   -33,   -33,   -33,   -21,
     -33,   -33,   -33,   -33,    18,   -32,    -1,    -4
  };

  const signed char
  TotsParser::yydefgoto_[] =
  {
      -1,     1,     2,     9,    10,    11,    12,    17,    26,    30,
      31,    32,    45,    46,    55,    65,    66,    67,    68,    69,
      58,    59,    60,    61,    50,    47,    41,    62
  };

  const signed char
  TotsParser::yytable_[] =
  {
      15,    40,    20,    14,    18,    13,    56,    19,    34,    35,
      36,    37,    38,    39,    48,    15,    23,    49,    22,    80,
      81,     3,     4,    70,     5,     6,     7,     8,    43,    15,
      13,    16,    13,    57,    44,    20,    42,    19,    24,    15,
      54,    -2,    25,    51,     4,    15,     5,     6,     7,     8,
      70,    71,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    52,   -60,    21,    96,    28,    51,    33,    85,    53,
      29,    34,    35,    36,    37,    38,    39,    82,    71,    63,
      64,    34,    35,    36,    37,    38,    39,     0,    84,    63,
      95,     0,     0,    13,    56,    34,    35,    36,    37,    38,
      39,     0,     0,    13,    56,     5,     6,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,    13,     0,    27,
      72,    83,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    72,     0,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    73,    74,    75,    76,    77,    78,    79,    80,
      81
  };

  const signed char
  TotsParser::yycheck_[] =
  {
       4,    33,     4,     4,    18,    32,    33,    21,    10,    11,
      12,    13,    14,    15,    17,    19,    20,    20,    19,    30,
      31,     0,     3,    55,     5,     6,     7,     8,    16,    33,
      32,     9,    32,    54,    22,     4,    40,    21,    19,    43,
      23,     0,    18,    47,     3,    49,     5,     6,     7,     8,
      82,    55,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    18,    32,    18,    22,    26,    70,    29,    72,    49,
      26,    10,    11,    12,    13,    14,    15,    63,    82,    18,
      19,    10,    11,    12,    13,    14,    15,    -1,    70,    18,
      19,    -1,    -1,    32,    33,    10,    11,    12,    13,    14,
      15,    -1,    -1,    32,    33,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    19,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    21,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    23,    24,    25,    26,    27,    28,    29,    30,
      31
  };

  const unsigned char
  TotsParser::yystos_[] =
  {
       0,    35,    36,     0,     3,     5,     6,     7,     8,    37,
      38,    39,    40,    32,    60,    61,     9,    41,    18,    21,
       4,    36,    60,    61,    19,    18,    42,    19,    39,    40,
      43,    44,    45,    41,    10,    11,    12,    13,    14,    15,
      59,    60,    61,    16,    22,    46,    47,    59,    17,    20,
      58,    61,    18,    47,    23,    48,    33,    53,    54,    55,
      56,    57,    61,    18,    19,    49,    50,    51,    52,    53,
      59,    61,    21,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    48,    22,    58,    61,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    19,    22
  };

  const unsigned char
  TotsParser::yyr1_[] =
  {
       0,    34,    35,    36,    36,    37,    37,    38,    39,    40,
      40,    40,    40,    40,    41,    41,    42,    42,    43,    43,
      43,    44,    45,    46,    46,    46,    47,    48,    48,    49,
      49,    49,    50,    51,    52,    53,    53,    53,    53,    53,
      54,    55,    56,    56,    56,    56,    56,    57,    57,    57,
      57,    58,    58,    59,    59,    59,    59,    59,    59,    59,
      60,    60,    61
  };

  const unsigned char
  TotsParser::yyr2_[] =
  {
       0,     2,     1,     0,     2,     1,     1,     5,     7,     0,
       1,     1,     1,     1,     0,     1,     0,     2,     1,     1,
       1,    10,     5,     0,     1,     3,     2,     0,     2,     1,
       1,     1,     3,     3,     2,     1,     1,     1,     1,     1,
       3,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const TotsParser::yytname_[] =
  {
  "$end", "error", "$undefined", "_NAMESPACE", "_CLASS", "_INTERNAL",
  "_PRIVATE", "_PROTECTED", "_PUBLIC", "_STATIC", "_VAR", "_VOID", "_INT",
  "_FLOAT", "_BOOL", "_CHAR", "_LPAREN", "_RPAREN", "_LCURLY", "_RCURLY",
  "_COMMA", "_DOT", "_SEMICOLON", "_EQ", "_ADD_EQ", "_SUB_EQ", "_MUL_EQ",
  "_DIV_EQ", "_ADD", "_SUB", "_MUL", "_DIV", "_ID", "_INT_LITERAL",
  "$accept", "root", "base_decl_list", "base_decl", "namespace_decl",
  "class_decl", "visibility_mod", "static_mod", "member_decl_list",
  "member_decl", "function_decl", "field_decl", "argument_list",
  "argument", "statement_list", "statement", "statement_block",
  "local_decl_stmt", "expr_stmt", "expr", "access_expr", "num_lit_expr",
  "assign_expr", "bin_expr", "var_declr", "type", "name", "simple_name", YY_NULLPTR
  };


  const unsigned short int
  TotsParser::yyrline_[] =
  {
       0,   147,   147,   151,   152,   156,   157,   161,   165,   170,
     171,   172,   173,   174,   178,   179,   183,   184,   188,   189,
     190,   194,   199,   204,   205,   206,   210,   214,   215,   219,
     220,   221,   225,   229,   233,   237,   238,   239,   240,   241,
     245,   249,   253,   254,   255,   256,   257,   261,   262,   263,
     264,   268,   269,   273,   274,   275,   276,   277,   278,   279,
     283,   284,   288
  };

  // Print the state stack on the debug stream.
  void
  TotsParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  TotsParser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  TotsParser::token_number_type
  TotsParser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33
    };
    const unsigned int user_token_number_max_ = 288;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 4 "TotsParser.yy" // lalr1.cc:1167
} } } } // Tots::Language::Syntax::Parser
#line 2206 "TotsParser.tab.cc" // lalr1.cc:1167
#line 291 "TotsParser.yy" // lalr1.cc:1168



void TotsParser::error(const std::string &err_message )
{
	std::cerr << "Error: " << err_message << std::endl;
}
