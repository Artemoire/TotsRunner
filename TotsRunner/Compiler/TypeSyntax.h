#pragma once

#include "SyntaxNode.h"

class TypeSyntax : public SyntaxNode
{	
public:
	char *identifier;

	TypeSyntax();
	TypeSyntax(char*);
};