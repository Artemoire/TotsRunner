#pragma once

#include "ExpressionSyntax.h"
#include "SimpleNameSyntax.h"

class VariableDeclaratorSyntax : public SyntaxNode
{
public:
	SimpleNameSyntax * identifier;
	ExpressionSyntax * initializer;

	VariableDeclaratorSyntax(SimpleNameSyntax *);
	VariableDeclaratorSyntax(SimpleNameSyntax *, ExpressionSyntax *);
};