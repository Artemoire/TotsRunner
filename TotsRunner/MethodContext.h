#pragma once

#include "defs.h"

class MethodContext
{
public:
	WRD pc;
	starray<UChar> * charcodes;
	WRD sp;
	starray<DWRD> * stack;
	starray<DWRD> * locals;
	starray<DWRD> * args;
	bool isReturn;

	
	MethodContext();
	MethodContext(starray<UChar> *, WRD, WRD, starray<DWRD> *, bool);
	~MethodContext();
	void release();
};