#pragma once

#include "TypeSyntax.h"
#include "VariableDeclaratorSyntax.h"

class ArgumentSyntax : public SyntaxNode
{
public:
	TypeSyntax * type;
	VariableDeclaratorSyntax * declarator;

	ArgumentSyntax(TypeSyntax *, VariableDeclaratorSyntax *);
};