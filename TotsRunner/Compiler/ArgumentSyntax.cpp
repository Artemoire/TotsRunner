#include "ArgumentSyntax.h"

ArgumentSyntax::ArgumentSyntax(TypeSyntax * t, VariableDeclaratorSyntax * d)
{
	kind = SyntaxKind::kArgumentSyntax;
	type = t;
	declarator = d;
}
