#pragma once

#include "MemberDeclarationSyntax.h"
#include "VisibilityModifierSyntax.h"
#include "StaticModifierSyntax.h"
#include "TypeSyntax.h"
#include "SimpleNameSyntax.h"

class FieldDeclaration : public MemberDeclarationSyntax
{
public:
	VisibilityModifierSyntax * visibility_modifier;
	StaticModifierSyntax * static_modifier;
	TypeSyntax * type;
	SimpleNameSyntax * identifier;

	FieldDeclaration(VisibilityModifierSyntax *, StaticModifierSyntax *, TypeSyntax *, SimpleNameSyntax *);
};