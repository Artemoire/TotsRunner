#include "SyntaxRoot.h"

SyntaxRoot::SyntaxRoot(std::vector<FunctionDeclarationSyntax*>* functions)
{
	kind = SyntaxKind::kSyntaxRoot;
	this->functions = functions;
}
