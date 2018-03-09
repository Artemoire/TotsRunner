#include "MethodContext.h"

MethodContext::MethodContext()
{
	charcodes = nullptr;
	stack = nullptr;
	args = nullptr;
}

MethodContext::MethodContext(starray<UChar> * charcodes, WRD stack, WRD locals, starray<DWRD> * args)
{
	this->pc = 0;
	this->sp = -1;
	this->charcodes = charcodes;
	this->stack = new starray<DWRD>(stack);
	this->locals = new starray<DWRD>(locals);
	this->args = args;
}

MethodContext::~MethodContext()
{
	release();
}

void MethodContext::release()
{
	pc = 0;
	sp = -1;
	delete stack;
	delete locals;
	delete args;
}
