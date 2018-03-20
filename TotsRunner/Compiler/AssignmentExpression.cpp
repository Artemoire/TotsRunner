#include "AssignmentExpression.h"
#include "SyntaxError.h"

AssignmentExpression::AssignmentExpression(ExpressionSyntax * id, ExpressionSyntax * e)
{
	kind = SyntaxKind::kAssignmentExpression;
	identifier = id;
	equals = e;
	if (id->kind != SyntaxKind::kIdentifierExpression)
	{
		SyntaxError::errors->push_back(new AssingmentSyntaxError());
	}
}
