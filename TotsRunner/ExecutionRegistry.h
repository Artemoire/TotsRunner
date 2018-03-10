#pragma once

#include "defs.h"
#include "MethodDef.h"

// TODO: Per module registry
class ExecutionRegistry
{
	static ExecutionRegistry * instance;
public:	
	ExecutionRegistry();
	~ExecutionRegistry();

	starray<MethodDef*> * methodDefTable;

	static ExecutionRegistry * getInstance();
	static ExecutionRegistry * create(starray<MethodDef*>*);

};