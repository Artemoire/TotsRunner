#pragma once

#include "ExpressionSyntax.h"
#include "Operators.h"

class BinaryOperatorExpression : public ExpressionSyntax
{
public:
	ExpressionSyntax * left;
	ExpressionSyntax * right;
	Tots::Language::Operators op;

	BinaryOperatorExpression(ExpressionSyntax *, ExpressionSyntax *,
		Tots::Language::Operators);
};