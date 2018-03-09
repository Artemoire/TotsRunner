#pragma once

#include "MethodContext.h"

class MethodDef
{
public:
	starray<UChar> * charcodes;
	WRD stack;
	WRD locals;
	WRD args;	
	/*starray<TypeDef> locals;
	starray<TypeDef> args;*/

	MethodDef();
	MethodDef(starray<UChar> *, WRD, WRD, WRD);
	MethodContext * call(starray<DWRD> * args);
};

MethodDef::MethodDef()
{
}

MethodDef::MethodDef(starray<UChar> * charcodes, WRD stack, WRD locals, WRD args)
{
	this->charcodes = charcodes;
	this->stack = stack;
	this->locals = locals;
	this->args = args;
}

MethodContext * MethodDef::call(starray<DWRD> * args)
{
	return new MethodContext(charcodes, stack, locals, args);
}
