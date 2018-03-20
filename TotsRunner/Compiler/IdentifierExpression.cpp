#include "IdentifierExpression.h"

IdentifierExpression::IdentifierExpression(char * id)
{
	kind = SyntaxKind::kIdentifierExpression;
	identifier = id;
}
