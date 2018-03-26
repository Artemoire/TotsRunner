#pragma once

#define ACCESS_KINDS(V) \
V(StaticModifierSyntax) \
V(VisibilityModifierSyntax) \

#define EXPRESSION_KINDS(V) \
V(AssignmentExpression) \
V(BinaryOperatorExpression) \
V(OperatorAssignExpression) \

#define FUNCTION_KINDS(V) \
V(ArgumentSyntax) \
V(FunctionDeclarationSyntax) \

#define NAME_KINDS(V) \
V(QualifiedNameSyntax) \
V(IdentifierNameSyntax) \

#define LITERAL_KINDS(V) \
V(NumericLiteralExpression) \

#define STATEMENT_KINDS(V) \
V(ExpressionStatement) \
V(LocalDeclarationStatement) \
V(StatementBlock) \

#define TYPE_KINDS(V) \
V(ExpressionDefinedType) \
V(PredefinedType) \
V(VoidType) \

#define VARIABLE_KINDS(V) \
V(VariableDeclaratorSyntax) \

#define DECLARE_ENUM(Name) k##Name,

enum SyntaxKind
{
	kUndefined,
	kSyntaxRoot,
	ACCESS_KINDS(DECLARE_ENUM)
#undef ACCESS_KINDS
	EXPRESSION_KINDS(DECLARE_ENUM)
#undef EXPRESSION_KINDS
	FUNCTION_KINDS(DECLARE_ENUM)
#undef FUNCTION_KINDS
	NAME_KINDS(DECLARE_ENUM)
#undef NAME_KINDS
	LITERAL_KINDS(DECLARE_ENUM)
#undef LITERAL_KINDS
	STATEMENT_KINDS(DECLARE_ENUM)
#undef STATEMENT_KINDS
	TYPE_KINDS(DECLARE_ENUM)
#undef TYPE_KINDS
	VARIABLE_KINDS(DECLARE_ENUM)
#undef VARIABLE_KINDS
};

#undef DECLARE_ENUM