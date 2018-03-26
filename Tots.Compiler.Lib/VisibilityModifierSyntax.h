#pragma once

#include "SyntaxNode.h"
#include "TypeVisibility.h"

class VisibilityModifierSyntax : public SyntaxNode
{
public:
	Tots::Language::TypeVisibility visibility;

	VisibilityModifierSyntax(Tots::Language::TypeVisibility);
};