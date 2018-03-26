#include "ClassDeclaration.h"

ClassDeclaration::ClassDeclaration(VisibilityModifierSyntax * v, StaticModifierSyntax * s, SimpleNameSyntax * id, std::vector<MemberDeclarationSyntax*> * m)
{
	kind = kClassDeclaration;
	visibility_modifier = v;
	static_modifier = s;
	identifier = id;
	members = m;
}
