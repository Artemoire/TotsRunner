#pragma once

#include "StatementSyntax.h"
#include <vector>

class StatementBlock : public StatementSyntax
{
public:
	std::vector<StatementSyntax*> *statements;

	StatementBlock(std::vector<StatementSyntax*> *);
};