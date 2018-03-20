#pragma once
#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#include "TotsParser.tab.hh"

namespace Tots
{
	namespace Language
	{
		namespace Syntax
		{
			namespace Parser
			{
				class TotsScanner : public yyFlexLexer {
				public:

					TotsScanner(std::istream *in) : yyFlexLexer(in)
					{
					};
					virtual ~TotsScanner() {
					};

					//get rid of override virtual function warning
					using FlexLexer::yylex;

					virtual int yylex(TotsParser::semantic_type * const lval);
					// YY_DECL defined in mc_lexer.l
					// Method body created by flex in mc_lexer.yy.cc


				private:
					/* yyval ptr */
					TotsParser::semantic_type *yylval = nullptr;
				};
			}
		}
	}
}