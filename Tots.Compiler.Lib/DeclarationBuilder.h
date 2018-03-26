#pragma once

#include "SyntaxRoot.h"
#include "ClassDeclaration.h"
#include "NamespaceDeclaration.h"

#include <vector>

class DeclarationBuilder
{
	std::vector<MemberDeclarationSyntax *> scope_stack;
	std::string current_namespace;

	void gen_namespace();
	void enter_scope(MemberDeclarationSyntax *);
	void leave_scope();

	void parse_namespace(NamespaceDeclaration *);

	void parse_class(ClassDeclaration *);
public:

	void parse_root(SyntaxRoot *);
};