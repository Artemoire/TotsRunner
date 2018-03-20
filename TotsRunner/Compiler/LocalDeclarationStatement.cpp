#include "LocalDeclarationStatement.h"

LocalDeclarationStatement::LocalDeclarationStatement(TypeSyntax *t, VariableDeclaratorSyntax *d)
{
	kind = SyntaxKind::kLocalDeclarationStatement;
	type = t;
	declarator = d;
}
