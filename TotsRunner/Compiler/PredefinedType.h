#pragma once

#include "TypeSyntax.h"
#include "PredefTypes.h"
#include "Keywords.h"

class PredefinedType : public TypeSyntax
{
public:
	Tots::Language::PredefTypes ptype;

	PredefinedType(Tots::Language::PredefTypes);
};