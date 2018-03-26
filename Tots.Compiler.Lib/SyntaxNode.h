#pragma once

#include "SyntaxKind.h"
#include <string>

class SyntaxNode
{
public:
	SyntaxKind kind;

	SyntaxNode * parent;

	SyntaxNode();
};