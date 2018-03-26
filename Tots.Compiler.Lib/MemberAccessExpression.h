#pragma once

#include "ExpressionSyntax.h"
#include "SimpleNameSyntax.h"

class MemberAccessExpression : public ExpressionSyntax
{
public:
	ExpressionSyntax * expr;
	SimpleNameSyntax * name;

	MemberAccessExpression(ExpressionSyntax *, SimpleNameSyntax *);
};