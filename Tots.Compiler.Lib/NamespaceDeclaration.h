#pragma once

#include "MemberDeclarationSyntax.h"
#include "NameSyntax.h"
#include <vector>

class NamespaceDeclaration : public MemberDeclarationSyntax
{
public:
	NameSyntax * name;
	std::vector<MemberDeclarationSyntax*> * declarations;

	NamespaceDeclaration(NameSyntax *, std::vector<MemberDeclarationSyntax*> *);
};