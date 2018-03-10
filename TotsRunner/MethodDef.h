#pragma once

#include "MethodContext.h"

class MethodDef
{
public:
	starray<UChar> * charcodes;
	WRD stack;
	WRD locals;
	WRD args;	
	bool isReturn;
	/*starray<TypeDef> locals;
	starray<TypeDef> args;*/

	MethodDef();
	MethodDef(starray<UChar> *, WRD, WRD, WRD, bool);
	MethodContext * call(starray<DWRD> * args);
};
