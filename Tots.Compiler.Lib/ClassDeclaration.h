#pragma once

#include "BaseTypeDeclaration.h"
#include "SimpleNameSyntax.h"
#include "StaticModifierSyntax.h"
#include "VisibilityModifierSyntax.h"
#include <vector>

class ClassDeclaration : public BaseTypeDeclaration
{
public:	
	VisibilityModifierSyntax * visibility_modifier;
	StaticModifierSyntax * static_modifier;
	SimpleNameSyntax * identifier;
	
	std::vector<MemberDeclarationSyntax*> * members;

	ClassDeclaration(VisibilityModifierSyntax *, StaticModifierSyntax *, SimpleNameSyntax *, std::vector<MemberDeclarationSyntax*> *);
};