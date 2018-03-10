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

#define AS_UI8 *(UChar*)
#define AS_UI16 *(UShort*)
#define AS_WRD *(WRD*)
#define AS_F32 *(Float*)
#define CURR_STACK stack->values[*sp]
#define NEXT_STACK stack->values[++*sp]
#define STACK_AND_PREV stack->values[(*sp)--]
#define CODE_AND_NEXT charcodes->values[(*pc)++]

void VirtualThreadWorker::run()
{
	while (*pc < charcodes->size)
	{
		CharCodes code = static_cast<CharCodes>(CODE_AND_NEXT);
		switch (code)
		{
			case (CharCodes::kLCNEG1):
			{
				AS_WRD(&NEXT_STACK) = -1;
				break;
			}
			case (CharCodes::kLC0):
			{
				AS_WRD(&NEXT_STACK) = 0;
				break;
			}
			case (CharCodes::kLC1):
			{
				AS_WRD(&NEXT_STACK) = 1;
				break;
			}
			case (CharCodes::kLC2):
			{
				AS_WRD(&NEXT_STACK) = 2;
				break;
			}
			case (CharCodes::kLC3):
			{
				AS_WRD(&NEXT_STACK) = 3;
				break;
			}
			case (CharCodes::kLVI8):
			{
				AS_UI8(&NEXT_STACK) = AS_UI8(&CODE_AND_NEXT);
				DLOG(stack->values[*sp]);
				break;
			}
			case (CharCodes::kLVI16):
			{
				AS_UI16(&NEXT_STACK) = AS_UI16(&CODE_AND_NEXT);
				(*pc)++;
				break;
			}
			case (CharCodes::kLVI32):
			{
				AS_WRD(&NEXT_STACK) = AS_WRD(&CODE_AND_NEXT);
				*pc += 3;
				DLOG(stack->values[*sp]);
				break;
			}
			case (CharCodes::kLVF32):
			{
				AS_WRD(&NEXT_STACK) = AS_WRD(&CODE_AND_NEXT);
				*pc += 3;
				DLOG(AS_F32 & CURR_STACK);
				break;
			}
			case (kLVLOC0):
			{
				if (locals->size < 1)
				{
					ERR("Invalid Program");
				}			
				NEXT_STACK = locals->values[0];
				break;
			}
			case (kLVLOC1):
			{
				if (locals->size < 2)
				{
					ERR("Invalid Program");
				}
				NEXT_STACK = locals->values[1];
				break;
			}
			case (kLVLOC2):
			{
				if (locals->size < 3)
				{
					ERR("Invalid Program");
				}
				NEXT_STACK = locals->values[2];
				break;
			}
			case (kLVLOC3):
			{
				if (locals->size < 4)
				{
					ERR("Invalid Program");
				}
				NEXT_STACK = locals->values[3];
				break;
			}
			case (kLVLOCI8):
			{
				UChar idx = AS_UI8(&CODE_AND_NEXT);
				if (locals->size < idx)
				{
					ERR("Invalid Program");
				}
				NEXT_STACK = locals->values[idx];
				break;
			}
			case (kLVLOCI16):
			{
				UShort idx = AS_UI16(&CODE_AND_NEXT);
				(*pc)++;
				if (locals->size < idx)
				{
					ERR("Invalid Program");
				}
				NEXT_STACK = locals->values[idx];
				break;
			}
			case (kLVALOCI16):
			{
				UShort idx = AS_UI16(&CODE_AND_NEXT);
				if (locals->size < idx)
				{
					ERR("Invalid Program");
				}
				AS_WRD(&NEXT_STACK) = (WRD)&locals->values[idx]; // TODO: NATIVE
				break;
			}
			case (kSTLOC0):
			{
				if (locals->size < 1)
				{
					ERR("Invalid Program");
				}
				locals->values[0] = STACK_AND_PREV;
				break;
			}
			case (kSTLOC1):
			{
				if (locals->size < 2)
				{
					ERR("Invalid Program");
				}
				locals->values[1] = STACK_AND_PREV;
				break;
			}
			case (kSTLOC2):
			{
				if (locals->size < 3)
				{
					ERR("Invalid Program");
				}
				locals->values[2] = STACK_AND_PREV;
				break;
			}
			case (kSTLOC3):
			{
				if (locals->size < 4)
				{
					ERR("Invalid Program");
				}
				locals->values[3] = STACK_AND_PREV;
				break;
			}
			case (kSTLOCI8):
			{
				UChar idx = AS_UI8(&CODE_AND_NEXT);
				if (locals->size < idx)
				{
					ERR("Invalid Program");
				}
				locals->values[idx] = STACK_AND_PREV;
				break;
			}			
			case (kSTLOCI16):
			{
				UShort idx = AS_UI16(&CODE_AND_NEXT);
				(*pc)++;
				if (locals->size < idx)
				{
					ERR("Invalid Program");
				}
				locals->values[idx] = STACK_AND_PREV;
				break;
			}
			case(CharCodes::kOP):
			{
				Ops::Op(static_cast<OpsExtensions>(CODE_AND_NEXT), &stack->values[--*sp], &stack->values[*sp + 1]);
				break;
			}
			case(CharCodes::kJEQ):
			{
				// LEFT HERE
				break;
			}
		}		
	}
	handleReturn();
}

#undef AS_UI8
#undef AS_UI16
#undef AS_WRD
#undef AS_F32
#undef CURR_STACK
#undef NEXT_STACK
#undef STACK_AND_PREV
#undef CODE_AND_NEXT

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
