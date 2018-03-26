#pragma once

#include "SyntaxNode.h"

enum TypeVisibility
{
	Internal,
	Private,
	Protected,
	Public
};

class VisibilityModifierSyntax : public SyntaxNode
{
public:
	TypeVisibility visibility;

	VisibilityModifierSyntax(TypeVisibility);
};