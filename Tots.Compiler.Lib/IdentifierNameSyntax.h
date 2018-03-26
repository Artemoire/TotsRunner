#pragma once

#include "SimpleNameSyntax.h"

class IdentifierNameSyntax : public SimpleNameSyntax
{
public:
	std::string identifier;

	IdentifierNameSyntax(std::string);
};