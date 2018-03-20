#include "TotsAotCompiler.h"
#include <iostream>
#include "SyntaxKind.h"
#include "LocalDeclarationStatement.h"
#include "NumericLiteralExpression.h"

using namespace std;

vector<char*> locals;

int findLocal(char * id)
{
	for (int i = 0; i < locals.size(); ++i)
		if (strcmp(locals[i], id) == 0)
			return i;
	return -1;
}

void compileExpression(ExpressionSyntax* e)
{
	switch (e->kind)
	{
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
				cout << "TODO EXPR STMT" << endl;
				break;
			}
			case SyntaxKind::kLocalDeclarationStatement:
			{
				LocalDeclarationStatement * stmt = (LocalDeclarationStatement*)statements[i];
				int idx = locals.size();
				if (findLocal(stmt->declarator->identifier) == -1)
				{
					locals.push_back(stmt->declarator->identifier);
					if (stmt->declarator->initializer != nullptr)
					{
						compileExpression(stmt->declarator->initializer);
						cout << "stloc " << idx << endl;
					}
				}
				else
				{
					cout << "ERROR LOCAL VARIABLE REDEFINITION" << endl;
				}
				//stmt->declarator->identifier map
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
