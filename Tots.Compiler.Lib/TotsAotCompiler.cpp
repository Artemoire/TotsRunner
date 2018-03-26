#include "TotsAotCompiler.h"

#include <iostream>

using namespace std;

SymbolTable locals;

char * declaring_local = nullptr;

#define SEMANTIC_ERROR 5
#define NOT_IMPLEMENTED_ERROR 3

#define NOT_IMPLEMENTED() \
cout << "NOT IMPLEMENTED" << endl; throw NOT_IMPLEMENTED_ERROR

// char * X;
#define ASSERT_NOT_BUILDING(X) if (locals.is_curr(X)) { \
cout << "ERROR cannot use value of '" << X << "' while it's being declared" << endl; \
throw SEMANTIC_ERROR; \
} \

// int LOC; char * ID;
#define ASSERT_EXISTING_LOC(LOC, ID) if (LOC == -1) { \
cout << "ERROR VARIABLE " << ID << " NOT FOUND" << endl; \
throw SEMANTIC_ERROR; \
} \

// int LOC; char * ID;
#define ASSERT_VALID_LOC(LOC, ID) if (!locals.is_valid_loc(LOC)) { \
cout << "ERROR " << ID << " CANNOT BE USED INSIDE THIS SCOPE" << endl; \
throw SEMANTIC_ERROR; \
} \

TypeSymbol Tots::Language::Compiler::TotsAotCompiler::compileExpression(ExpressionSyntax* e, bool root)
{
	switch (e->kind)
	{
		case kAssignmentExpression:
		{
			AssignmentExpression * expr = (AssignmentExpression*)e;
			char * var_id = expr->identifier->identifier;
			ASSERT_NOT_BUILDING(var_id);
			int loc = locals.loc_of(var_id);
			ASSERT_EXISTING_LOC(loc, var_id);
			ASSERT_VALID_LOC(loc, var_id);

			TypeSymbol equalsType = compileExpression(expr->equals, false);
			// TODO: Type cast ?

			cout << "stloc " << loc << endl;
			if (!root)
				cout << "ldloc " << loc << endl;

			break;
		}
		case kBinaryOperatorExpression:
		{
			BinaryOperatorExpression * expr = (BinaryOperatorExpression *)e;
			TypeSymbol leftType = compileExpression(expr->left, false);
			TypeSymbol rightType = compileExpression(expr->right, false);
			// TODO cast right to left if possible throw err if not
			switch (expr->op)
			{
				case Operators::Add:
				{
					cout << "Add" << endl;
					break;
				}
				case Operators::Sub:
				{
					cout << "Sub" << endl;
					break;
				}
				case Operators::Mul:
				{
					cout << "Mul" << endl;
					break;
				}
				case Operators::Div:
				{
					cout << "Div" << endl;
					break;
				}
				default:
					break;
			}
			break;
		}
		case kIdentifierExpression:
		{
			IdentifierExpression * expr = (IdentifierExpression *)e;
			char * var_id = expr->identifier;
			ASSERT_NOT_BUILDING(var_id);
			int loc = locals.loc_of(var_id);
			ASSERT_EXISTING_LOC(loc, var_id);
			ASSERT_VALID_LOC(loc, var_id);

			cout << "ldloc " << loc << endl;

			return locals.get(loc).type;
			break;
		}
		case kNumericLiteralExpression:
		{
			NumericLiteralExpression * expr = (NumericLiteralExpression*)e;
			cout << "LVI32 " << expr->value << endl;
			return TypeSymbol(PredefTypes::_INT);
			break;
		}

		default:
		{
			cout << "ERROR UNKNOWN EXPR" << endl;
			break;
		}
	}
}

void Tots::Language::Compiler::TotsAotCompiler::compileFunction(vector<StatementSyntax*> * s)
{
	locals.clear();
	vector<StatementSyntax*> statements = *s;
	for (int i = 0; i < statements.size(); ++i)
	{
		switch (statements[i]->kind)
		{
			case SyntaxKind::kExpressionStatement:
			{
				ExpressionStatement * stmt = (ExpressionStatement *)statements[i];
				// TODO : check valid expression statements
				compileExpression(stmt->expression, true);
				break;
			}
			case SyntaxKind::kLocalDeclarationStatement:
			{
				LocalDeclarationStatement * stmt = (LocalDeclarationStatement*)statements[i];
				locals.curr(stmt->declarator->identifier); // set in symbol table id of symbol that is being built
				TypeSymbol type;
				bool exprdef = false;
				switch (stmt->type->kind)
				{
					case SyntaxKind::kExpressionDefinedType:
					{
						exprdef = true;
						break;
					}
					case SyntaxKind::kNamedType:
					{
						NOT_IMPLEMENTED();
						break;
					}
					case SyntaxKind::kPredefinedType:
					{
						type = TypeSymbol(((PredefinedType*)stmt->type)->ptype);
						break;
					}
					case SyntaxKind::kVoidType:
					{
						cout << "Variable cannot be of void type" << endl;
						throw SEMANTIC_ERROR;
						break;
					}
				}
				int loc = locals.loc_of(stmt->declarator->identifier);
				if (loc != -1)
				{
					cout << "Variable " << stmt->declarator->identifier << " redefinition" << endl;
					throw SEMANTIC_ERROR;
				}
				if (stmt->declarator->initializer != nullptr)
				{
					TypeSymbol exprtype = (compileExpression(stmt->declarator->initializer, false));
					if (exprdef)
					{
						type = exprtype;
					}
					else
					{
						if (exprtype.predefined && type.predefined)
						{
							if (exprtype.ptype != type.ptype)
							{
								// TODO: CAST TO TYPE.PTYPE
							}
						}					
					}
					locals.add(stmt->declarator->identifier, type);
					cout << "stloc " << loc << endl;
				}
				else
				{
					locals.add(stmt->declarator->identifier, type);
				}
				locals.curr(nullptr);

				break;
			}
			case SyntaxKind::kStatementBlock:
			{
				NOT_IMPLEMENTED();
				break;
			}
			default:
				break;
		}

	}
}
