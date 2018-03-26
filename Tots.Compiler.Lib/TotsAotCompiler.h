#pragma once

#include <vector>
#include "ExpressionSyntaxDefs.h"
#include "StatementSyntaxDefs.h"
#include "TypeSyntaxDefs.h"

#include "SymbolTable.h"

namespace Tots
{
	namespace Language
	{
		namespace Compiler
		{
			class TotsAotCompiler
			{
				public:
					TypeSymbol compileExpression(ExpressionSyntax*, bool);
					void compileFunction(std::vector<StatementSyntax*>*);
			};
		}
	}
}