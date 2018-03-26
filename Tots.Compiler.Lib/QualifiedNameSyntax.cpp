#include "QualifiedNameSyntax.h"

QualifiedNameSyntax::QualifiedNameSyntax(NameSyntax * l, NameSyntax * r)
{
	kind = kQualifiedNameSyntax;
	left = l;
	right = r;
}

std::string QualifiedNameSyntax::to_string()
{
	return left->to_string() + "." + right->to_string();
}
