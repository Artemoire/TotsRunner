#pragma once

#include "TypeSyntax.h"
#include "PredefTypes.h"

class PredefinedType : public TypeSyntax
{
public:
	Tots::Language::PredefTypes ptype;

	PredefinedType(Tots::Language::PredefTypes);
};