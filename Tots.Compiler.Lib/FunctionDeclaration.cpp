#include "FunctionDeclaration.h"

FunctionDeclaration::FunctionDeclaration(VisibilityModifierSyntax * v, StaticModifierSyntax * s, TypeSyntax *type, SimpleNameSyntax * id, std::vector<ArgumentSyntax*>* args, std::vector<StatementSyntax*>* stmts)
{
	kind = SyntaxKind::kFunctionDeclaration;
	visibility_modifier = v;
	static_modifier = s;
	returnType = type;
	identifier = id;
	argList = args;
	statements = stmts;	
}
