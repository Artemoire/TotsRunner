#include "VariableDeclaratorSyntax.h"

VariableDeclaratorSyntax::VariableDeclaratorSyntax(SimpleNameSyntax *id)
{
	kind = SyntaxKind::kVariableDeclaratorSyntax;
	identifier = id;
	initializer = nullptr;
}

VariableDeclaratorSyntax::VariableDeclaratorSyntax(SimpleNameSyntax *id, ExpressionSyntax *init)
{
	kind = SyntaxKind::kVariableDeclaratorSyntax;
	identifier = id;
	initializer = init;
}
