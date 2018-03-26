#include "NamespaceDeclaration.h"

NamespaceDeclaration::NamespaceDeclaration(NameSyntax * n, std::vector<MemberDeclarationSyntax*> * d)
{
	kind = kNamespaceDeclaration;
	name = n;
	declarations = d;
}
