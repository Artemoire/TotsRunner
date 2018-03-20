#pragma once

#include "StatementSyntax.h"
#include "TypeSyntax.h"
#include "VariableDeclaratorSyntax.h"

class LocalDeclarationStatement : public StatementSyntax
{
public:
	TypeSyntax *type;
	VariableDeclaratorSyntax *declarator;

	LocalDeclarationStatement(TypeSyntax *, VariableDeclaratorSyntax *);
};