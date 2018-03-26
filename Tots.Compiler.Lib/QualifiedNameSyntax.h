#pragma once

#include "SimpleNameSyntax.h"

class QualifiedNameSyntax : public NameSyntax
{
public:
	NameSyntax * left;
	NameSyntax * right;

	QualifiedNameSyntax(NameSyntax *, NameSyntax *);

	std::string to_string();
};