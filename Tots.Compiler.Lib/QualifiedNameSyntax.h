#pragma once

#include "SimpleNameSyntax.h"

class QualifiedNameSyntax : public NameSyntax
{
public:
	NameSyntax * left;
	SimpleNameSyntax * right;

	QualifiedNameSyntax(NameSyntax *, SimpleNameSyntax *);
};