#pragma once

#include <vector>
#include "SyntaxNode.h"
#include "FunctionDeclarationSyntax.h"

class SyntaxRoot : public SyntaxNode
{
public:
	std::vector<FunctionDeclarationSyntax*>* functions;

	SyntaxRoot(std::vector<FunctionDeclarationSyntax*>* functions);
};