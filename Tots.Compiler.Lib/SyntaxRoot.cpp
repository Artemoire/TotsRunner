#include "SyntaxRoot.h"

SyntaxRoot::SyntaxRoot(std::vector<MemberDeclarationSyntax*>* d)
{
	kind = SyntaxKind::kSyntaxRoot;
	this->declarations = d;
}
