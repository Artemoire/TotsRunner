#include "AssignmentExpression.h"
#include "SyntaxError.h"

AssignmentExpression::AssignmentExpression(ExpressionSyntax * id, ExpressionSyntax * e)
{
	kind = SyntaxKind::kAssignmentExpression;
	identifier = id; // TODO: SEMANTIC CHECK
	//identifier = (IdentifierExpression*)id;
	//if (id->kind != SyntaxKind::kIdentifierExpression)
	//{
	//	identifier = nullptr;
	//	// TODO: SEMANTIC ERROR
	//}		
	equals = e;
}
