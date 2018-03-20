#include "OperatorAssignExpression.h"

OperatorAssignExpression::OperatorAssignExpression(ExpressionSyntax * id, ExpressionSyntax * eq, Tots::Language::Operators o) : AssignmentExpression(id, eq)
{
	kind = SyntaxKind::kOperatorAssignExpression;
	op = o;
}
