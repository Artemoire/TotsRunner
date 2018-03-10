#pragma once

#include <vector>
#include "defs.h"
#include "MethodDef.h"

class MethodDefTableBuilder
{
	vector<MethodDef*> defs;
public:	
	void add(MethodDef*);
	starray<MethodDef*> * build();
};