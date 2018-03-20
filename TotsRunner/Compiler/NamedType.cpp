#include "NamedType.h"

NamedType::NamedType(char * id) : TypeSyntax(id)
{
	kind = SyntaxKind::kNamedType;
}
