#pragma once

#include "ExpressionSyntax.h"

class VariableDeclaratorSyntax : public SyntaxNode
{
public:
	char * identifier;
	ExpressionSyntax * initializer;

	VariableDeclaratorSyntax(char *);
	VariableDeclaratorSyntax(char *, ExpressionSyntax *);
};