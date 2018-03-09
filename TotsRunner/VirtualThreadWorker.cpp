#include "VirtualThreadWorker.h"
#include "Ops.h"

VirtualThreadWorker::VirtualThreadWorker()
{
	csp = -1;
	callstack = new starray<MethodContext*>(100);
	started = false;
	pc = nullptr;
	charcodes = nullptr;
	stack = nullptr;
	locals = nullptr;
	args = nullptr;
}

void VirtualThreadWorker::start(MethodContext *mi)
{
	if (started)
		return;
	started = true;
	handleCall(mi);
	while (csp < -1)
	{
		run();
	}	
}

void VirtualThreadWorker::run()
{
	while (*pc < charcodes->size)
	{
		CharCodes code = static_cast<CharCodes>(charcodes->values[(*pc)++]);
		switch (code)
		{
			case (CharCodes::kLVI_1):
			{
				*(WRD*)(&stack->values[++*sp]) = -1;
				break;
			}
			case (CharCodes::kLVI0):
			{
				*(WRD*)(&stack->values[++*sp]) = 0;
				break;
			}
			case (CharCodes::kLVI8):
			{
				*(UChar*)(&stack->values[++*sp]) = *(UChar*)(&charcodes->values[(*pc)++]);
				break;
			}
			case (CharCodes::kLVI16):
			{
				*(UShort*)(&stack->values[++*sp]) = *(UShort*)(&charcodes->values[(*pc)++]);
				*pc++;
				break;
			}
			case (CharCodes::kLVI32):
			{
				*(WRD*)(&stack->values[++*sp]) = *(WRD*)(&charcodes->values[(*pc)++]);
				*pc += 3;
				DLOG(stack->values[*sp]);
				break;
			}
			case (CharCodes::kLVF32):
			{
				*(WRD*)(&stack->values[++*sp]) = *(WRD*)(&charcodes->values[(*pc)++]);
				*pc += 3;
				DLOG(*(Float*)&stack->values[*sp]);
				break;
			}
			case(CharCodes::kOP):
			{
				Ops::Op(static_cast<OpsExtensions>(charcodes->values[(*pc)++]), &stack->values[--*sp], &stack->values[*sp + 1]);
				break;
			}
		}		
	}
	handleReturn();
}

void VirtualThreadWorker::handleCall(MethodContext * mi)
{
	callstack->values[++csp] = mi;
	pc = &mi->pc;
	charcodes = mi->charcodes;
	sp = &mi->sp;
	stack = mi->stack;
	locals = mi->locals;
	args = mi->args;
}

void VirtualThreadWorker::handleReturn()
{
	MethodContext * mc = callstack->values[csp];
	delete mc;
	--csp;
}
