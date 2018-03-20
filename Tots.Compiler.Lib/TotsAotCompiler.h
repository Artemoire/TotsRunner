#pragma once

#include <vector>
#include "StatementSyntax.h"

namespace Tots
{
	namespace Language
	{
		namespace Compiler
		{
			class TotsAotCompiler
			{
				public:
					void compileFunction(std::vector<StatementSyntax*>*);
			};
		}
	}
}