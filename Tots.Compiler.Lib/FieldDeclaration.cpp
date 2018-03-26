#include "FieldDeclaration.h"

FieldDeclaration::FieldDeclaration(VisibilityModifierSyntax * v, StaticModifierSyntax * s, TypeSyntax * t, SimpleNameSyntax * id)
{
	kind = SyntaxKind::kFieldDeclaration;
	visibility_modifier = v;
	static_modifier = s;
	type = t;
	identifier = id;
}
