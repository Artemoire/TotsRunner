#pragma once

#include <vector>

#include "FunctionDefBuilder.h"

class ModuleBuilder
{
public:
	std::vector<FunctionDefBuilder> functionDefs;

	void add(FunctionDefBuilder);


};