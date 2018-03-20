#include "NumericLiteralExpression.h"

NumericLiteralExpression::NumericLiteralExpression(unsigned long v)
{
	kind = SyntaxKind::kNumericLiteralExpression;
	value = v;
}
