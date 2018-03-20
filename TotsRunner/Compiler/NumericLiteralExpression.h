#pragma once

#include "ExpressionSyntax.h"

class NumericLiteralExpression : public ExpressionSyntax
{
public:
	unsigned long long value;

	NumericLiteralExpression(unsigned long);
};