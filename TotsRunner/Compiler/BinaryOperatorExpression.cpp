#include "BinaryOperatorExpression.h"

BinaryOperatorExpression::BinaryOperatorExpression(ExpressionSyntax * l, ExpressionSyntax * r, Tots::Language::Operators o)
{
	kind = SyntaxKind::kBinaryOperatorExpression;
	left = l;
	right = r;
	op = o;
}
