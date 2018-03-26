#pragma once

#include "TypeSyntax.h"
#include <string>

class NameSyntax : public TypeSyntax
{
public:
	virtual std::string to_string() = 0;
};
