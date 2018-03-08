#pragma once

#include "defs.h"
#include <vector>
#include "MethodInstance.h"

class MethodDef
{
public:
	vector<UChar> charcodes;

	MethodDef();
	MethodInstance init();
};
