#include "DeclarationBuilder.h"

#include  <iostream>

void DeclarationBuilder::gen_namespace()
{
	current_namespace = "";
	for (int i = 0; i < scope_stack.size(); ++i)
	{
		switch (scope_stack[i]->kind)
		{
			case SyntaxKind::kNamespaceDeclaration:
			{
				current_namespace += ((NamespaceDeclaration*)scope_stack[i])->name->to_string() + ".";
				break;
			}
			case SyntaxKind::kClassDeclaration:
			{
				current_namespace += ((ClassDeclaration*)scope_stack[i])->identifier->to_string() + ".";
				break;
			}			
			default:
				throw 1;
				break;
		}
	}
	if (scope_stack.size() != 0)
		current_namespace = current_namespace.substr(0, current_namespace.size() - 1);

	std::cout << current_namespace << std::endl;
}

void DeclarationBuilder::enter_scope(MemberDeclarationSyntax * m)
{
	scope_stack.push_back(m);
	gen_namespace();
}

void DeclarationBuilder::leave_scope()
{
	scope_stack.pop_back();
	gen_namespace();
}

void DeclarationBuilder::parse_namespace(NamespaceDeclaration * ns)
{
	enter_scope(ns);
	for (int i = 0; i < ns->declarations->size(); ++i)
	{
		switch ((*ns->declarations)[i]->kind)
		{
			case SyntaxKind::kNamespaceDeclaration:
			{
				parse_namespace((NamespaceDeclaration*)(*ns->declarations)[i]);
				break;
			}
			case SyntaxKind::kClassDeclaration:
			{
				parse_class((ClassDeclaration*)(*ns->declarations)[i]);
				break;
			}
			default:
				throw 1;
				break;
		}
	}
	leave_scope();
}

void DeclarationBuilder::parse_class(ClassDeclaration * c)
{
	enter_scope(c);
	for (int i = 0; i < c->members->size(); ++i)
	{
		switch ((*c->members)[i]->kind)
		{			
			case SyntaxKind::kClassDeclaration:
			{
				parse_class((ClassDeclaration*)(*c->members)[i]);
				break;
			}
			default:
				
				break;
		}
	}
	leave_scope();
}

void DeclarationBuilder::parse_root(SyntaxRoot * root)
{
	for (int i = 0; i < root->declarations->size(); ++i)
	{
		switch ((*root->declarations)[i]->kind)
		{
			case SyntaxKind::kNamespaceDeclaration:
			{
				parse_namespace((NamespaceDeclaration*)(*root->declarations)[i]);
				break;
			}
			case SyntaxKind::kClassDeclaration:
			{
				parse_class((ClassDeclaration*)(*root->declarations)[i]);
				break;
			}
			default:
				throw 1;
				break;
		}
	}
}
