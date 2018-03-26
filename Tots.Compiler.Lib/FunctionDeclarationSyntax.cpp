#include "FunctionDeclarationSyntax.h"

FunctionDeclarationSyntax::FunctionDeclarationSyntax(TypeSyntax *type, std::string id, std::vector<ArgumentSyntax*>* args, std::vector<StatementSyntax*>* stmts)
{
	kind = SyntaxKind::kFunctionDeclarationSyntax;
	statements = stmts;
	argList = args;
	returnType = type;
	identifier = id;
}
