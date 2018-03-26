#pragma once

#include "ExpressionSyntax.h"
#include "IdentifierExpression.h"

class AssignmentExpression : public ExpressionSyntax
{
public:
	IdentifierExpression * identifier;
	ExpressionSyntax * equals;

	AssignmentExpression(ExpressionSyntax *, ExpressionSyntax *);
};