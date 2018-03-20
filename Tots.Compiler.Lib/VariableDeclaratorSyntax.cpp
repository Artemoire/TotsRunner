#include "VariableDeclaratorSyntax.h"

VariableDeclaratorSyntax::VariableDeclaratorSyntax(char *id)
{
	kind = SyntaxKind::kVariableDeclaratorSyntax;
	identifier = id;
	initializer = nullptr;
}

VariableDeclaratorSyntax::VariableDeclaratorSyntax(char *id, ExpressionSyntax *init)
{
	kind = SyntaxKind::kVariableDeclaratorSyntax;
	identifier = id;
	initializer = init;
}
