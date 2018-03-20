#pragma once

#include "SyntaxNode.h"
#include "TypeSyntax.h"
#include "ArgumentSyntax.h"
#include "StatementSyntax.h"
#include <vector>

class FunctionDeclarationSyntax : public SyntaxNode
{
public:	
	char *identifier;
	TypeSyntax *returnType;
	std::vector<ArgumentSyntax*> *argList;
	std::vector<StatementSyntax*> *statements;

	FunctionDeclarationSyntax(TypeSyntax *, char *, std::vector<ArgumentSyntax*> *, std::vector<StatementSyntax*> *);
};