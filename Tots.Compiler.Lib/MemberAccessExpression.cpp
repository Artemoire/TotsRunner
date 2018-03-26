#include "MemberAccessExpression.h"

MemberAccessExpression::MemberAccessExpression(ExpressionSyntax * e, SimpleNameSyntax * n)
{
	expr = e;
	name = n;
}
