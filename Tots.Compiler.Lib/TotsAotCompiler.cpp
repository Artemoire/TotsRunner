#include "TotsAotCompiler.h"

#include <iostream>

#include "SyntaxKind.h"

#include "ExpressionStatement.h"
#include "LocalDeclarationStatement.h"

#include "AssignmentExpression.h"
#include "BinaryOperatorExpression.h"
#include "IdentifierExpression.h"
#include "NumericLiteralExpression.h"
#include "OperatorAssignExpression.h"


using namespace std;

void Tots::Language::Compiler::TotsAotCompiler::compileExpression(ExpressionSyntax* e, bool root)
{
	switch (e->kind)
	{
		case kAssignmentExpression:
		{
			AssignmentExpression * expr = (AssignmentExpression*)e;			
			int loc = locals.loc_of(((IdentifierExpression*)expr->identifier)->identifier);
			if (loc != -1)
			{
				if (locals.is_valid_loc(loc))
				{
					compileExpression(expr->equals, false);
					cout << "stloc " << loc << endl;
					if (!root)
						cout << "ldloc " << loc << endl;
				}
				else
				{
					cout << " ERROR VAR CANNOT BE USED IN THIS SCOPE" << endl;
				}
			}
			else
			{
				cout << "ERROR UNDEFINED VAR" << endl;
			}
			
			break;
		}
		case kNumericLiteralExpression:
		{
			NumericLiteralExpression * expr = (NumericLiteralExpression*)e;
			cout << "LVI32 " << expr->value << endl;
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
				int loc = locals.add(stmt->declarator->identifier);
				if (loc != -1)
				{
					if (stmt->declarator->initializer != nullptr)
					{
						compileExpression(stmt->declarator->initializer, false);
						cout << "stloc " << loc << endl;
					}
				}
				else
				{
					cout << "ERROR LOCAL VARIABLE REDEFINITION" << endl;
				}
				break;
			}			
			case SyntaxKind::kStatementBlock:
			{
				cout << "TODO STMT BLOCK STMT" << endl;
				break;
			}
			default:
				break;
		}

	}
}
