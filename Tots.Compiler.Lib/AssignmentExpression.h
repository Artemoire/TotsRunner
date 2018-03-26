#pragma once

#include "ExpressionSyntax.h"

class AssignmentExpression : public ExpressionSyntax
{
public:
	ExpressionSyntax * identifier;
	ExpressionSyntax * equals;

	AssignmentExpression(ExpressionSyntax *, ExpressionSyntax *);
};