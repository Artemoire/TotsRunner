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

	
	MethodContext();
	MethodContext(starray<UChar> *, WRD, WRD, starray<DWRD> *);
	~MethodContext();
	void release();
};