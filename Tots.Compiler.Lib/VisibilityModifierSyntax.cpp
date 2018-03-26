#include "VisibilityModifierSyntax.h"

VisibilityModifierSyntax::VisibilityModifierSyntax(Tots::Language::TypeVisibility v)
{
	kind = SyntaxKind::kVisibilityModifierSyntax;
	visibility = v;
}
