#include "ExpressionStatement.h"

ExpressionStatement::ExpressionStatement(ExpressionSyntax * e)
{
	kind = SyntaxKind::kExpressionStatement;
	expression = e;
}
