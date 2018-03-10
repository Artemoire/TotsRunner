#include "MethodDef.h"

MethodDef::MethodDef()
{
}

MethodDef::MethodDef(starray<UChar> * charcodes, WRD stack, WRD locals, WRD args, bool isReturn)
{
	this->charcodes = charcodes;
	this->stack = stack;
	this->locals = locals;
	this->args = args;
	this->isReturn = isReturn;
}

MethodContext * MethodDef::call(starray<DWRD> * args)
{
	return new MethodContext(charcodes, stack, locals, args, isReturn);
}
