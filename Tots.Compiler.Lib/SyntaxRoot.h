#pragma once

#include <vector>
#include "SyntaxNode.h"
#include "MemberDeclarationSyntax.h"

class SyntaxRoot : public SyntaxNode
{
public:
	std::vector<MemberDeclarationSyntax*>* declarations;

	SyntaxRoot(std::vector<MemberDeclarationSyntax*>*);
};