#pragma once

#include "MemberDeclarationSyntax.h"
#include "VisibilityModifierSyntax.h"
#include "StaticModifierSyntax.h"
#include "TypeSyntax.h"
#include "SimpleNameSyntax.h"
#include "ArgumentSyntax.h"
#include "StatementSyntax.h"
#include <vector>

class FunctionDeclaration : public MemberDeclarationSyntax
{
public:	
	VisibilityModifierSyntax * visibility_modifier;
	StaticModifierSyntax * static_modifier;	

	TypeSyntax * returnType;
	SimpleNameSyntax * identifier;

	std::vector<ArgumentSyntax*> * argList;
	std::vector<StatementSyntax*> * statements;

	FunctionDeclaration(VisibilityModifierSyntax *, StaticModifierSyntax *, TypeSyntax *, SimpleNameSyntax *, std::vector<ArgumentSyntax*> *, std::vector<StatementSyntax*> *);
};