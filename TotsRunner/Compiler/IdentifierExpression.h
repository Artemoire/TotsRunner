#pragma once

#include "ExpressionSyntax.h"

class IdentifierExpression : public ExpressionSyntax
{
public:
	char * identifier;

	IdentifierExpression(char *);
};