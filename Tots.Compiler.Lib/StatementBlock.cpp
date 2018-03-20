#include "StatementBlock.h"

StatementBlock::StatementBlock(std::vector<StatementSyntax*>* stmts)
{
	kind = SyntaxKind::kStatementBlock;
	statements = stmts;
}
