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
#line 43 "TotsParser.yy" // lalr1.cc:413

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

#undef yylex
#define yylex scanner.yylex

#line 73 "TotsParser.tab.cc" // lalr1.cc:413


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
#line 140 "TotsParser.tab.cc" // lalr1.cc:479

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
      case 32: // argument
        value.copy< ArgumentSyntax* > (other.value);
        break;

      case 38: // expr
      case 39: // id_expr
      case 40: // num_lit_expr
      case 41: // assign_expr
      case 42: // bin_expr
        value.copy< ExpressionSyntax* > (other.value);
        break;

      case 30: // function_decl
        value.copy< FunctionDeclarationSyntax* > (other.value);
        break;

      case 34: // statement
      case 35: // statement_block
      case 36: // local_decl_stmt
      case 37: // expr_stmt
        value.copy< StatementSyntax* > (other.value);
        break;

      case 28: // root
        value.copy< SyntaxRoot* > (other.value);
        break;

      case 44: // type
        value.copy< TypeSyntax* > (other.value);
        break;

      case 43: // var_declr
        value.copy< VariableDeclaratorSyntax* > (other.value);
        break;

      case 25: // _ID
        value.copy< char* > (other.value);
        break;

      case 31: // argument_list
        value.copy< std::vector<ArgumentSyntax*>* > (other.value);
        break;

      case 29: // function_decl_list
        value.copy< std::vector<FunctionDeclarationSyntax*>* > (other.value);
        break;

      case 33: // statement_list
        value.copy< std::vector<StatementSyntax*>* > (other.value);
        break;

      case 26: // _INT_LITERAL
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
      case 32: // argument
        value.copy< ArgumentSyntax* > (v);
        break;

      case 38: // expr
      case 39: // id_expr
      case 40: // num_lit_expr
      case 41: // assign_expr
      case 42: // bin_expr
        value.copy< ExpressionSyntax* > (v);
        break;

      case 30: // function_decl
        value.copy< FunctionDeclarationSyntax* > (v);
        break;

      case 34: // statement
      case 35: // statement_block
      case 36: // local_decl_stmt
      case 37: // expr_stmt
        value.copy< StatementSyntax* > (v);
        break;

      case 28: // root
        value.copy< SyntaxRoot* > (v);
        break;

      case 44: // type
        value.copy< TypeSyntax* > (v);
        break;

      case 43: // var_declr
        value.copy< VariableDeclaratorSyntax* > (v);
        break;

      case 25: // _ID
        value.copy< char* > (v);
        break;

      case 31: // argument_list
        value.copy< std::vector<ArgumentSyntax*>* > (v);
        break;

      case 29: // function_decl_list
        value.copy< std::vector<FunctionDeclarationSyntax*>* > (v);
        break;

      case 33: // statement_list
        value.copy< std::vector<StatementSyntax*>* > (v);
        break;

      case 26: // _INT_LITERAL
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
  TotsParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const FunctionDeclarationSyntax* v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
  TotsParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const StatementSyntax* v)
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
  TotsParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const char* v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
  TotsParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::vector<ArgumentSyntax*>* v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
  TotsParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::vector<FunctionDeclarationSyntax*>* v)
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
      case 32: // argument
        value.template destroy< ArgumentSyntax* > ();
        break;

      case 38: // expr
      case 39: // id_expr
      case 40: // num_lit_expr
      case 41: // assign_expr
      case 42: // bin_expr
        value.template destroy< ExpressionSyntax* > ();
        break;

      case 30: // function_decl
        value.template destroy< FunctionDeclarationSyntax* > ();
        break;

      case 34: // statement
      case 35: // statement_block
      case 36: // local_decl_stmt
      case 37: // expr_stmt
        value.template destroy< StatementSyntax* > ();
        break;

      case 28: // root
        value.template destroy< SyntaxRoot* > ();
        break;

      case 44: // type
        value.template destroy< TypeSyntax* > ();
        break;

      case 43: // var_declr
        value.template destroy< VariableDeclaratorSyntax* > ();
        break;

      case 25: // _ID
        value.template destroy< char* > ();
        break;

      case 31: // argument_list
        value.template destroy< std::vector<ArgumentSyntax*>* > ();
        break;

      case 29: // function_decl_list
        value.template destroy< std::vector<FunctionDeclarationSyntax*>* > ();
        break;

      case 33: // statement_list
        value.template destroy< std::vector<StatementSyntax*>* > ();
        break;

      case 26: // _INT_LITERAL
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
      case 32: // argument
        value.move< ArgumentSyntax* > (s.value);
        break;

      case 38: // expr
      case 39: // id_expr
      case 40: // num_lit_expr
      case 41: // assign_expr
      case 42: // bin_expr
        value.move< ExpressionSyntax* > (s.value);
        break;

      case 30: // function_decl
        value.move< FunctionDeclarationSyntax* > (s.value);
        break;

      case 34: // statement
      case 35: // statement_block
      case 36: // local_decl_stmt
      case 37: // expr_stmt
        value.move< StatementSyntax* > (s.value);
        break;

      case 28: // root
        value.move< SyntaxRoot* > (s.value);
        break;

      case 44: // type
        value.move< TypeSyntax* > (s.value);
        break;

      case 43: // var_declr
        value.move< VariableDeclaratorSyntax* > (s.value);
        break;

      case 25: // _ID
        value.move< char* > (s.value);
        break;

      case 31: // argument_list
        value.move< std::vector<ArgumentSyntax*>* > (s.value);
        break;

      case 29: // function_decl_list
        value.move< std::vector<FunctionDeclarationSyntax*>* > (s.value);
        break;

      case 33: // statement_list
        value.move< std::vector<StatementSyntax*>* > (s.value);
        break;

      case 26: // _INT_LITERAL
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
  TotsParser::make__ID (const char*& v)
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
      case 32: // argument
        value.move< ArgumentSyntax* > (that.value);
        break;

      case 38: // expr
      case 39: // id_expr
      case 40: // num_lit_expr
      case 41: // assign_expr
      case 42: // bin_expr
        value.move< ExpressionSyntax* > (that.value);
        break;

      case 30: // function_decl
        value.move< FunctionDeclarationSyntax* > (that.value);
        break;

      case 34: // statement
      case 35: // statement_block
      case 36: // local_decl_stmt
      case 37: // expr_stmt
        value.move< StatementSyntax* > (that.value);
        break;

      case 28: // root
        value.move< SyntaxRoot* > (that.value);
        break;

      case 44: // type
        value.move< TypeSyntax* > (that.value);
        break;

      case 43: // var_declr
        value.move< VariableDeclaratorSyntax* > (that.value);
        break;

      case 25: // _ID
        value.move< char* > (that.value);
        break;

      case 31: // argument_list
        value.move< std::vector<ArgumentSyntax*>* > (that.value);
        break;

      case 29: // function_decl_list
        value.move< std::vector<FunctionDeclarationSyntax*>* > (that.value);
        break;

      case 33: // statement_list
        value.move< std::vector<StatementSyntax*>* > (that.value);
        break;

      case 26: // _INT_LITERAL
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
      case 32: // argument
        value.copy< ArgumentSyntax* > (that.value);
        break;

      case 38: // expr
      case 39: // id_expr
      case 40: // num_lit_expr
      case 41: // assign_expr
      case 42: // bin_expr
        value.copy< ExpressionSyntax* > (that.value);
        break;

      case 30: // function_decl
        value.copy< FunctionDeclarationSyntax* > (that.value);
        break;

      case 34: // statement
      case 35: // statement_block
      case 36: // local_decl_stmt
      case 37: // expr_stmt
        value.copy< StatementSyntax* > (that.value);
        break;

      case 28: // root
        value.copy< SyntaxRoot* > (that.value);
        break;

      case 44: // type
        value.copy< TypeSyntax* > (that.value);
        break;

      case 43: // var_declr
        value.copy< VariableDeclaratorSyntax* > (that.value);
        break;

      case 25: // _ID
        value.copy< char* > (that.value);
        break;

      case 31: // argument_list
        value.copy< std::vector<ArgumentSyntax*>* > (that.value);
        break;

      case 29: // function_decl_list
        value.copy< std::vector<FunctionDeclarationSyntax*>* > (that.value);
        break;

      case 33: // statement_list
        value.copy< std::vector<StatementSyntax*>* > (that.value);
        break;

      case 26: // _INT_LITERAL
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
      case 32: // argument
        yylhs.value.build< ArgumentSyntax* > ();
        break;

      case 38: // expr
      case 39: // id_expr
      case 40: // num_lit_expr
      case 41: // assign_expr
      case 42: // bin_expr
        yylhs.value.build< ExpressionSyntax* > ();
        break;

      case 30: // function_decl
        yylhs.value.build< FunctionDeclarationSyntax* > ();
        break;

      case 34: // statement
      case 35: // statement_block
      case 36: // local_decl_stmt
      case 37: // expr_stmt
        yylhs.value.build< StatementSyntax* > ();
        break;

      case 28: // root
        yylhs.value.build< SyntaxRoot* > ();
        break;

      case 44: // type
        yylhs.value.build< TypeSyntax* > ();
        break;

      case 43: // var_declr
        yylhs.value.build< VariableDeclaratorSyntax* > ();
        break;

      case 25: // _ID
        yylhs.value.build< char* > ();
        break;

      case 31: // argument_list
        yylhs.value.build< std::vector<ArgumentSyntax*>* > ();
        break;

      case 29: // function_decl_list
        yylhs.value.build< std::vector<FunctionDeclarationSyntax*>* > ();
        break;

      case 33: // statement_list
        yylhs.value.build< std::vector<StatementSyntax*>* > ();
        break;

      case 26: // _INT_LITERAL
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
#line 108 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< SyntaxRoot* > () = new SyntaxRoot(yystack_[0].value.as< std::vector<FunctionDeclarationSyntax*>* > ()); driver.root = yylhs.value.as< SyntaxRoot* > (); }
#line 1211 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 112 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< std::vector<FunctionDeclarationSyntax*>* > () = new vector<FunctionDeclarationSyntax*>(); yylhs.value.as< std::vector<FunctionDeclarationSyntax*>* > ()->push_back(yystack_[0].value.as< FunctionDeclarationSyntax* > ()); }
#line 1217 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 113 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< std::vector<FunctionDeclarationSyntax*>* > () = yystack_[1].value.as< std::vector<FunctionDeclarationSyntax*>* > (); yylhs.value.as< std::vector<FunctionDeclarationSyntax*>* > ()->push_back(yystack_[0].value.as< FunctionDeclarationSyntax* > ()); }
#line 1223 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 118 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< FunctionDeclarationSyntax* > () = new FunctionDeclarationSyntax(yystack_[7].value.as< TypeSyntax* > (), yystack_[6].value.as< char* > (), yystack_[4].value.as< std::vector<ArgumentSyntax*>* > (), yystack_[1].value.as< std::vector<StatementSyntax*>* > ()); }
#line 1229 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 122 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< std::vector<ArgumentSyntax*>* > () = new vector<ArgumentSyntax*>(); }
#line 1235 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 123 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< std::vector<ArgumentSyntax*>* > () = new vector<ArgumentSyntax*>(); yylhs.value.as< std::vector<ArgumentSyntax*>* > ()->push_back(yystack_[0].value.as< ArgumentSyntax* > ()); }
#line 1241 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 124 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< std::vector<ArgumentSyntax*>* > () = yystack_[2].value.as< std::vector<ArgumentSyntax*>* > (); yylhs.value.as< std::vector<ArgumentSyntax*>* > ()->push_back(yystack_[0].value.as< ArgumentSyntax* > ()); }
#line 1247 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 128 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< ArgumentSyntax* > () = new ArgumentSyntax(yystack_[1].value.as< TypeSyntax* > (), yystack_[0].value.as< VariableDeclaratorSyntax* > ()); }
#line 1253 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 132 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< std::vector<StatementSyntax*>* > () = new vector<StatementSyntax*>(); }
#line 1259 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 133 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< std::vector<StatementSyntax*>* > () = yystack_[1].value.as< std::vector<StatementSyntax*>* > (); yylhs.value.as< std::vector<StatementSyntax*>* > ()->push_back(yystack_[0].value.as< StatementSyntax* > ()); }
#line 1265 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 137 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< StatementSyntax* > () = yystack_[0].value.as< StatementSyntax* > (); }
#line 1271 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 138 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< StatementSyntax* > () = yystack_[0].value.as< StatementSyntax* > (); }
#line 1277 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 139 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< StatementSyntax* > () = yystack_[0].value.as< StatementSyntax* > (); }
#line 1283 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 143 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< StatementSyntax* > () = new StatementBlock(yystack_[1].value.as< std::vector<StatementSyntax*>* > ()); }
#line 1289 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 147 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< StatementSyntax* > () = new LocalDeclarationStatement(yystack_[2].value.as< TypeSyntax* > (), yystack_[1].value.as< VariableDeclaratorSyntax* > ()); }
#line 1295 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 151 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< StatementSyntax* > () = new ExpressionStatement(yystack_[1].value.as< ExpressionSyntax* > ()); }
#line 1301 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 155 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< ExpressionSyntax* > () = yystack_[0].value.as< ExpressionSyntax* > (); }
#line 1307 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 156 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< ExpressionSyntax* > () = yystack_[0].value.as< ExpressionSyntax* > (); }
#line 1313 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 157 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< ExpressionSyntax* > () = yystack_[0].value.as< ExpressionSyntax* > (); }
#line 1319 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 158 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< ExpressionSyntax* > () = yystack_[0].value.as< ExpressionSyntax* > (); }
#line 1325 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 162 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< ExpressionSyntax* > () = new IdentifierExpression(yystack_[0].value.as< char* > ()); }
#line 1331 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 166 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< ExpressionSyntax* > () = new NumericLiteralExpression(yystack_[0].value.as< unsigned long > ()); }
#line 1337 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 170 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< ExpressionSyntax* > () = new AssignmentExpression(yystack_[2].value.as< ExpressionSyntax* > (), yystack_[0].value.as< ExpressionSyntax* > ()); }
#line 1343 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 171 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< ExpressionSyntax* > () = new OperatorAssignExpression(yystack_[2].value.as< ExpressionSyntax* > (), yystack_[0].value.as< ExpressionSyntax* > (), Tots::Language::Operators::Add); }
#line 1349 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 172 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< ExpressionSyntax* > () = new OperatorAssignExpression(yystack_[2].value.as< ExpressionSyntax* > (), yystack_[0].value.as< ExpressionSyntax* > (), Tots::Language::Operators::Sub); }
#line 1355 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 173 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< ExpressionSyntax* > () = new OperatorAssignExpression(yystack_[2].value.as< ExpressionSyntax* > (), yystack_[0].value.as< ExpressionSyntax* > (), Tots::Language::Operators::Mul); }
#line 1361 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 174 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< ExpressionSyntax* > () = new OperatorAssignExpression(yystack_[2].value.as< ExpressionSyntax* > (), yystack_[0].value.as< ExpressionSyntax* > (), Tots::Language::Operators::Div); }
#line 1367 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 178 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< ExpressionSyntax* > () = new BinaryOperatorExpression(yystack_[2].value.as< ExpressionSyntax* > (), yystack_[0].value.as< ExpressionSyntax* > (), Tots::Language::Operators::Add); }
#line 1373 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 179 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< ExpressionSyntax* > () = new BinaryOperatorExpression(yystack_[2].value.as< ExpressionSyntax* > (), yystack_[0].value.as< ExpressionSyntax* > (), Tots::Language::Operators::Sub); }
#line 1379 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 180 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< ExpressionSyntax* > () = new BinaryOperatorExpression(yystack_[2].value.as< ExpressionSyntax* > (), yystack_[0].value.as< ExpressionSyntax* > (), Tots::Language::Operators::Mul); }
#line 1385 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 181 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< ExpressionSyntax* > () = new BinaryOperatorExpression(yystack_[2].value.as< ExpressionSyntax* > (), yystack_[0].value.as< ExpressionSyntax* > (), Tots::Language::Operators::Div); }
#line 1391 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 185 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< VariableDeclaratorSyntax* > () = new VariableDeclaratorSyntax(yystack_[0].value.as< char* > ()); }
#line 1397 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 186 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< VariableDeclaratorSyntax* > () = new VariableDeclaratorSyntax(yystack_[2].value.as< char* > (), yystack_[0].value.as< ExpressionSyntax* > ()); }
#line 1403 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 190 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< TypeSyntax* > () = new ExpressionDefinedType(); }
#line 1409 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 191 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< TypeSyntax* > () = new VoidType(); }
#line 1415 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 192 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< TypeSyntax* > () = new PredefinedType(Tots::Language::PredefTypes::_INT); }
#line 1421 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 193 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< TypeSyntax* > () = new PredefinedType(Tots::Language::PredefTypes::_FLOAT); }
#line 1427 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 194 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< TypeSyntax* > () = new PredefinedType(Tots::Language::PredefTypes::_BOOL); }
#line 1433 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 195 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< TypeSyntax* > () = new PredefinedType(Tots::Language::PredefTypes::_CHAR); }
#line 1439 "TotsParser.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 196 "TotsParser.yy" // lalr1.cc:859
    { yylhs.value.as< TypeSyntax* > () = new NamedType(yystack_[0].value.as< char* > ()); }
#line 1445 "TotsParser.tab.cc" // lalr1.cc:859
    break;


#line 1449 "TotsParser.tab.cc" // lalr1.cc:859
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


  const signed char TotsParser::yypact_ninf_ = -25;

  const signed char TotsParser::yytable_ninf_ = -42;

  const signed char
  TotsParser::yypact_[] =
  {
      51,   -25,   -25,   -25,   -25,   -25,   -25,   -25,     2,    51,
     -25,   -21,   -25,   -25,     3,    51,    -7,   -25,   -12,     4,
      51,    -2,   -25,   -25,   -25,   -18,    27,   -25,   -25,    61,
     -25,   -25,   -25,   -25,   -25,   -25,    -9,   -25,   -25,   -25,
     -25,    49,   -12,   -18,   -18,   -18,   -18,   -18,   -18,   -18,
     -18,   -18,    37,   -25,    13,    61,    61,    61,    61,    61,
     -14,   -14,   -25,   -25,   -25,   -25
  };

  const unsigned char
  TotsParser::yydefact_[] =
  {
       0,    35,    36,    37,    38,    39,    40,    41,     0,     2,
       3,     0,     1,     4,     0,     6,     0,     7,     0,     0,
       0,    33,     9,    10,     8,     0,     0,    22,    23,    34,
      18,    19,    20,    21,    10,     5,    22,    11,    12,    13,
      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,     0,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    15,    16
  };

  const signed char
  TotsParser::yypgoto_[] =
  {
     -25,   -25,   -25,     8,   -25,     9,   -16,   -25,   -25,   -25,
     -25,   -24,   -25,   -25,   -25,   -25,    -6,   -15
  };

  const signed char
  TotsParser::yydefgoto_[] =
  {
      -1,     8,     9,    10,    16,    17,    26,    37,    38,    39,
      40,    41,    30,    31,    32,    33,    22,    11
  };

  const signed char
  TotsParser::yytable_[] =
  {
      18,    29,    12,    19,    14,    18,    20,    27,    28,    50,
      51,    42,    15,    21,    25,    23,   -41,    13,    52,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    65,    24,
       1,     2,     3,     4,     5,     6,    54,    42,    34,    35,
       1,     2,     3,     4,     5,     6,     0,     0,    34,    64,
       0,     0,    36,    28,     1,     2,     3,     4,     5,     6,
       0,     0,    36,    28,    53,    43,    44,    45,    46,    47,
      48,    49,    50,    51,     0,     0,     7,    43,    44,    45,
      46,    47,    48,    49,    50,    51
  };

  const signed char
  TotsParser::yycheck_[] =
  {
      15,    25,     0,    10,    25,    20,    13,    25,    26,    23,
      24,    26,     9,    25,    16,    11,    25,     9,    34,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    15,    20,
       3,     4,     5,     6,     7,     8,    42,    52,    11,    12,
       3,     4,     5,     6,     7,     8,    -1,    -1,    11,    12,
      -1,    -1,    25,    26,     3,     4,     5,     6,     7,     8,
      -1,    -1,    25,    26,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    25,    16,    17,    18,
      19,    20,    21,    22,    23,    24
  };

  const unsigned char
  TotsParser::yystos_[] =
  {
       0,     3,     4,     5,     6,     7,     8,    25,    28,    29,
      30,    44,     0,    30,    25,     9,    31,    32,    44,    10,
      13,    25,    43,    11,    32,    16,    33,    25,    26,    38,
      39,    40,    41,    42,    11,    12,    25,    34,    35,    36,
      37,    38,    44,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    33,    15,    43,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    12,    15
  };

  const unsigned char
  TotsParser::yyr1_[] =
  {
       0,    27,    28,    29,    29,    30,    31,    31,    31,    32,
      33,    33,    34,    34,    34,    35,    36,    37,    38,    38,
      38,    38,    39,    40,    41,    41,    41,    41,    41,    42,
      42,    42,    42,    43,    43,    44,    44,    44,    44,    44,
      44,    44
  };

  const unsigned char
  TotsParser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     8,     0,     1,     3,     2,
       0,     2,     1,     1,     1,     3,     3,     2,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const TotsParser::yytname_[] =
  {
  "$end", "error", "$undefined", "_VAR", "_VOID", "_INT", "_FLOAT",
  "_BOOL", "_CHAR", "_LPAREN", "_RPAREN", "_LCURLY", "_RCURLY", "_COMMA",
  "_DOT", "_SEMICOLON", "_EQ", "_ADD_EQ", "_SUB_EQ", "_MUL_EQ", "_DIV_EQ",
  "_ADD", "_SUB", "_MUL", "_DIV", "_ID", "_INT_LITERAL", "$accept", "root",
  "function_decl_list", "function_decl", "argument_list", "argument",
  "statement_list", "statement", "statement_block", "local_decl_stmt",
  "expr_stmt", "expr", "id_expr", "num_lit_expr", "assign_expr",
  "bin_expr", "var_declr", "type", YY_NULLPTR
  };


  const unsigned char
  TotsParser::yyrline_[] =
  {
       0,   108,   108,   112,   113,   117,   122,   123,   124,   128,
     132,   133,   137,   138,   139,   143,   147,   151,   155,   156,
     157,   158,   162,   166,   170,   171,   172,   173,   174,   178,
     179,   180,   181,   185,   186,   190,   191,   192,   193,   194,
     195,   196
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
      25,    26
    };
    const unsigned int user_token_number_max_ = 281;
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
#line 1821 "TotsParser.tab.cc" // lalr1.cc:1167
#line 199 "TotsParser.yy" // lalr1.cc:1168



void TotsParser::error(const std::string &err_message )
{
	std::cerr << "Error: " << err_message << std::endl;
}
