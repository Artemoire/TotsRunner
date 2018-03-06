#pragma once

#include "defs.h"

enum Type
{
	//NULL = 0,
	INT = 0,
	FLOAT,
	//ARRAY,
	OBJECTREF
};

class ValueObject
{
public:
	Type type;
	WORD value;
};