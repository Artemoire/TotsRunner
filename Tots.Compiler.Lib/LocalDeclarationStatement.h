#pragma once

#include "StatementSyntax.h"
#include "TypeSyntax.h"
#include "VariableDeclaratorSyntax.h"

class LocalDeclarationStatement : public StatementSyntax
{
public:
	TypeSyntax *type;
	VariableDeclaratorSyntax *declarator;

	// TODO: SEMANTIC CHECK VOID OR VAR AND NO DECLARATOR
	LocalDeclarationStatement(TypeSyntax *, VariableDeclaratorSyntax *);
};