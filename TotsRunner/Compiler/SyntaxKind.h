#pragma once

#define EXPRESSION_KINDS(V) \
V(AssignmentExpression) \
V(BinaryOperatorExpression) \
V(IdentifierExpression) \
V(NumericLiteralExpression) \
V(OperatorAssignExpression) \

#define FUNCTION_KINDS(V) \
V(ArgumentSyntax) \
V(FunctionDeclarationSyntax) \

#define STATEMENT_KINDS(V) \
V(ExpressionStatement) \
V(LocalDeclarationStatement) \
V(StatementBlock) \

#define TYPE_KINDS(V) \
V(ExpressionDefinedType) \
V(NamedType) \
V(PredefinedType) \

#define VARIABLE_KINDS(V) \
V(VariableDeclaratorSyntax) \

#define DECLARE_ENUM(Name) k##Name,

enum SyntaxKind
{
	kUndefined,
	kSyntaxRoot,
	EXPRESSION_KINDS(DECLARE_ENUM)
#undef EXPRESSION_KINDS
	FUNCTION_KINDS(DECLARE_ENUM)
#undef FUNCTION_KINDS
	STATEMENT_KINDS(DECLARE_ENUM)
#undef STATEMENT_KINDS
	TYPE_KINDS(DECLARE_ENUM)
#undef TYPE_KINDS
	VARIABLE_KINDS(DECLARE_ENUM)
#undef VARIABLE_KINDS
};

#undef DECLARE_ENUM