#include "IdentifierNameSyntax.h"

std::string IdentifierNameSyntax::to_string()
{
	return identifier;
}

IdentifierNameSyntax::IdentifierNameSyntax(std::string id)
{
	kind = kIdentifierNameSyntax;
	identifier = id;
}
