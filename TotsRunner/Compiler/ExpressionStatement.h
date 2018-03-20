#pragma once

#include "StatementSyntax.h"
#include "ExpressionSyntax.h"

class ExpressionStatement : public StatementSyntax
{
public:
	ExpressionSyntax * expression;

	ExpressionStatement(ExpressionSyntax *);
};