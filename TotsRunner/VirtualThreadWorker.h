#pragma once

#include "defs.h"
#include "MethodContext.h"
#include "CharCodes.h"

#include <vector>

class VirtualThreadWorker
{
public:
	VirtualThreadWorker();

	void start(MethodContext * mi);
	void run();

protected:
	WRD csp;
	starray<MethodContext*> * callstack;	

	bool started;

	WRD * pc;
	starray<UChar> * charcodes;	
	WRD * sp;
	starray<DWRD> * stack;
	starray<DWRD> * locals;
	starray<DWRD> * args;

	void handleCall(MethodContext * );
	void handleReturn();
};