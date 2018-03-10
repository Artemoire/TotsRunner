#include "ExecutionRegistry.h"

ExecutionRegistry * ExecutionRegistry::instance = nullptr;

ExecutionRegistry::ExecutionRegistry()
{
}

ExecutionRegistry::~ExecutionRegistry()
{
	delete[] methodDefTable->values;
	methodDefTable->values = nullptr;
	delete methodDefTable;
}

ExecutionRegistry * ExecutionRegistry::getInstance()
{	
	return instance;
}

ExecutionRegistry * ExecutionRegistry::create(starray<MethodDef*>* methodDefTable)
{
	if (instance != nullptr)
		return instance;
	instance = new ExecutionRegistry();
	instance->methodDefTable = methodDefTable;
}
