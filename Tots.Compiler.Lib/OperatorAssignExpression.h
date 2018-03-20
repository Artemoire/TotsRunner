#pragma once

#include "AssignmentExpression.h"
#include "Operators.h"

class OperatorAssignExpression : public AssignmentExpression
{
public:
	Tots::Language::Operators op;

	OperatorAssignExpression(ExpressionSyntax *, ExpressionSyntax *,
		Tots::Language::Operators);
};