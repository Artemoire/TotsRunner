#pragma once
#include "ValueObject.h"

namespace Arith
{
	void Add(ValueObject*, ValueObject*);
	void Sub(ValueObject*, ValueObject*);
	void Mul(ValueObject*, ValueObject*);
	void Div(ValueObject*, ValueObject*);
}