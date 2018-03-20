#pragma once

#include <vector>
#include "StatementSyntax.h"
#include "ExpressionSyntax.h"
#include "SymbolTable.h"

namespace Tots
{
	namespace Language
	{
		namespace Compiler
		{
			class TotsAotCompiler
			{
				SymbolTable locals;

				public:
					void compileExpression(ExpressionSyntax*, bool);
					void compileFunction(std::vector<StatementSyntax*>*);
			};
		}
	}
}