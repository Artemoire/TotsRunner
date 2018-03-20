#include "ExpressionDefinedType.h"

ExpressionDefinedType::ExpressionDefinedType() : TypeSyntax((char*)Tots::Language::Keywords::var_keyword)
{
	kind = SyntaxKind::kExpressionDefinedType;
}
