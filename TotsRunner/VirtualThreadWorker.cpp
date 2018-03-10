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
#define AS_I32 *(I32*)
#define AS_F32 *(Float*)
#define CURR_STACK stack->values[*sp]
#define NEXT_STACK stack->values[++*sp]
#define STACK_AND_PREV stack->values[(*sp)--]
#define CODE_AND_NEXT charcodes->values[(*pc)++]

#define LOCAL_UI8_FROM_CODE(LOCAL) UChar LOCAL = AS_UI8(&CODE_AND_NEXT)
#define LOCAL_UI16_FROM_CODE(LOCAL) UShort LOCAL = AS_UI16(&CODE_AND_NEXT); (*pc)++
#define LOCAL_WRD_FROM_CODE(LOCAL) WRD LOCAL = AS_WRD(&CODE_AND_NEXT); (*pc) += 3
#define LOCAL_I32_FROM_CODE(LOCAL) I32 LOCAL = AS_I32(&CODE_AND_NEXT); (*pc) += 3

#define ASSERT_SIZE(X,SIZE)	\
if (X->size < SIZE)			\
{							\
ERR("Invalid Program");		\
}							\

void VirtualThreadWorker::run()
{
	while (*pc < charcodes->size)
	{
		CharCodes code = static_cast<CharCodes>(CODE_AND_NEXT);
		switch (code)
		{
			case(CharCodes::kNOP):
			{
				break;
			}
			case(CharCodes::kPOP):
			{
				*(sp)--;
				break;
			}
			case (CharCodes::kLCNEG1):
			{
				AS_WRD(&NEXT_STACK) = -1;
				DLOG("-1");
				break;
			}
			case (CharCodes::kLC0):
			{
				AS_WRD(&NEXT_STACK) = 0;
				DLOG("0");
				break;
			}
			case (CharCodes::kLC1):
			{
				AS_WRD(&NEXT_STACK) = 1;
				DLOG("1");
				break;
			}
			case (CharCodes::kLC2):
			{
				AS_WRD(&NEXT_STACK) = 2;
				DLOG("2");
				break;
			}
			case (CharCodes::kLC3):
			{
				AS_WRD(&NEXT_STACK) = 3;
				DLOG("3");
				break;
			}
			case (CharCodes::kLVI8):
			{
				AS_WRD(&NEXT_STACK) = AS_UI8(&CODE_AND_NEXT);
				DLOG(stack->values[*sp]);
				break;
			}
			case (CharCodes::kLVI16):
			{
				AS_WRD(&NEXT_STACK) = AS_UI16(&CODE_AND_NEXT);
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
				ASSERT_SIZE(locals, 1);
				NEXT_STACK = locals->values[0];
				DLOG("LOC0: " << locals->values[0]);
				break;
			}
			case (kLVLOC1):
			{
				ASSERT_SIZE(locals, 2);
				NEXT_STACK = locals->values[1];
				break;
			}
			case (kLVLOC2):
			{
				ASSERT_SIZE(locals, 3);
				NEXT_STACK = locals->values[2];
				break;
			}
			case (kLVLOC3):
			{
				ASSERT_SIZE(locals, 4);
				NEXT_STACK = locals->values[3];
				break;
			}
			case (kLVLOCI8):
			{
				LOCAL_UI8_FROM_CODE(idx);
				ASSERT_SIZE(locals, idx);
				NEXT_STACK = locals->values[idx];
				break;
			}
			case (kLVLOCI16):
			{
				LOCAL_UI16_FROM_CODE(idx);
				ASSERT_SIZE(locals, idx);
				NEXT_STACK = locals->values[idx];
				break;
			}
			case (kLVALOCI16):
			{
				LOCAL_UI16_FROM_CODE(idx);
				ASSERT_SIZE(locals, idx);
				AS_WRD(&NEXT_STACK) = (WRD)&locals->values[idx]; // TODO: NATIVE
				break;
			}
			case (kSTLOC0):
			{
				ASSERT_SIZE(locals, 1);
				locals->values[0] = STACK_AND_PREV;
				break;
			}
			case (kSTLOC1):
			{
				ASSERT_SIZE(locals, 2);
				locals->values[1] = STACK_AND_PREV;
				break;
			}
			case (kSTLOC2):
			{
				ASSERT_SIZE(locals, 3);
				locals->values[2] = STACK_AND_PREV;
				break;
			}
			case (kSTLOC3):
			{
				ASSERT_SIZE(locals, 4);
				locals->values[3] = STACK_AND_PREV;
				break;
			}
			case (kSTLOCI8):
			{
				LOCAL_UI8_FROM_CODE(idx);
				ASSERT_SIZE(locals, idx);
				locals->values[idx] = STACK_AND_PREV;
				break;
			}
			case (kSTLOCI16):
			{
				LOCAL_UI16_FROM_CODE(idx);
				ASSERT_SIZE(locals, idx);
				locals->values[idx] = STACK_AND_PREV;
				break;
			}
			case(CharCodes::kOP):
			{
				Ops::Op(static_cast<OpsExtensions>(CODE_AND_NEXT), &stack->values[--*sp], &stack->values[*sp + 1]);
				break;
			}			
			case(CharCodes::kJMPOP):
			{
				jump(static_cast<JmpExtensions>(CODE_AND_NEXT));
				break;
			}
		}
	}
	handleReturn();
}

void VirtualThreadWorker::jump(JmpExtensions op)
{
	switch (op)
	{
		case(JmpExtensions::kJMP):
		{
			LOCAL_WRD_FROM_CODE(idx);
			ASSERT_SIZE(charcodes, idx);
			*pc = idx;
			break;
		}
		case(JmpExtensions::kJEQ32):
		{
			LOCAL_WRD_FROM_CODE(idx);
			ASSERT_SIZE(charcodes, idx);
			WRD v2 = AS_WRD(&STACK_AND_PREV);
			WRD v1 = AS_WRD(&STACK_AND_PREV);
			if (v1 == v2)
				*pc = idx;
			break;
		}
		case(JmpExtensions::kJNE32):
		{
			LOCAL_WRD_FROM_CODE(idx);
			ASSERT_SIZE(charcodes, idx);
			WRD v2 = AS_WRD(&STACK_AND_PREV);
			WRD v1 = AS_WRD(&STACK_AND_PREV);
			if (v1 != v2)
				*pc = idx;
			break;
		}
		case (JmpExtensions::kJGEI32):
		{
			LOCAL_WRD_FROM_CODE(idx);
			ASSERT_SIZE(charcodes, idx);
			I32 v2 = AS_I32(&STACK_AND_PREV);
			I32 v1 = AS_I32(&STACK_AND_PREV);
			if (v1 >= v2)
				*pc = idx;
			break;
		}
		case (JmpExtensions::kJGEUI32):
		{
			LOCAL_WRD_FROM_CODE(idx);
			ASSERT_SIZE(charcodes, idx);
			WRD v2 = AS_WRD(&STACK_AND_PREV);
			WRD v1 = AS_WRD(&STACK_AND_PREV);
			if (v1 >= v2)
				*pc = idx;
			break;
		}
		case (JmpExtensions::kJGTI32):
		{
			LOCAL_WRD_FROM_CODE(idx);
			ASSERT_SIZE(charcodes, idx);
			I32 v2 = AS_I32(&STACK_AND_PREV);
			I32 v1 = AS_I32(&STACK_AND_PREV);
			if (v1 > v2)
				*pc = idx;
			break;
		}
		case (JmpExtensions::kJGTUI32):
		{
			LOCAL_WRD_FROM_CODE(idx);
			ASSERT_SIZE(charcodes, idx);
			WRD v2 = AS_WRD(&STACK_AND_PREV);
			WRD v1 = AS_WRD(&STACK_AND_PREV);
			if (v1 > v2)
				*pc = idx;
			break;
		}
		case (JmpExtensions::kJLEI32):
		{
			LOCAL_WRD_FROM_CODE(idx);
			ASSERT_SIZE(charcodes, idx);
			I32 v2 = AS_I32(&STACK_AND_PREV);
			I32 v1 = AS_I32(&STACK_AND_PREV);
			if (v1 <= v2)
				*pc = idx;
			break;
		}
		case (JmpExtensions::kJLEUI32):
		{
			LOCAL_WRD_FROM_CODE(idx);
			ASSERT_SIZE(charcodes, idx);
			WRD v2 = AS_WRD(&STACK_AND_PREV);
			WRD v1 = AS_WRD(&STACK_AND_PREV);
			if (v1 <= v2)
				*pc = idx;
			break;
		}
		case (JmpExtensions::kJLTI32):
		{
			LOCAL_WRD_FROM_CODE(idx);
			ASSERT_SIZE(charcodes, idx);
			I32 v2 = AS_I32(&STACK_AND_PREV);
			I32 v1 = AS_I32(&STACK_AND_PREV);
			if (v1 < v2)
				*pc = idx;
			break;
		}
		case (JmpExtensions::kJLTUI32):
		{
			LOCAL_WRD_FROM_CODE(idx);
			ASSERT_SIZE(charcodes, idx);
			WRD v2 = AS_WRD(&STACK_AND_PREV);
			WRD v1 = AS_WRD(&STACK_AND_PREV);
			if (v1 < v2)
				*pc = idx;
			break;
		}
		case(JmpExtensions::kJMPs):
		{
			LOCAL_UI8_FROM_CODE(idx);
			ASSERT_SIZE(charcodes, idx);
			*pc = idx;
			break;
		}
		case(JmpExtensions::kJEQ32s):
		{
			LOCAL_UI8_FROM_CODE(idx);
			ASSERT_SIZE(charcodes, idx);
			DWRD v2 = STACK_AND_PREV;
			DWRD v1 = STACK_AND_PREV;
			if (v1 == v2)
				*pc = idx;
			break;
		}
		case(JmpExtensions::kJNE32s):
		{
			LOCAL_UI8_FROM_CODE(idx);
			ASSERT_SIZE(charcodes, idx);
			DWRD v2 = STACK_AND_PREV;
			DWRD v1 = STACK_AND_PREV;
			if (v1 != v2)
				*pc = idx;
			break;
		}
		case (JmpExtensions::kJGEI32s):
		{
			LOCAL_UI8_FROM_CODE(idx);
			ASSERT_SIZE(charcodes, idx);
			I32 v2 = AS_I32(&STACK_AND_PREV);
			I32 v1 = AS_I32(&STACK_AND_PREV);
			if (v1 >= v2)
				*pc = idx;
			break;
		}
		case (JmpExtensions::kJGEUI32s):
		{
			LOCAL_UI8_FROM_CODE(idx);
			ASSERT_SIZE(charcodes, idx);
			WRD v2 = AS_WRD(&STACK_AND_PREV);
			WRD v1 = AS_WRD(&STACK_AND_PREV);
			if (v1 >= v2)
				*pc = idx;
			break;
		}
		case (JmpExtensions::kJGTI32s):
		{
			LOCAL_UI8_FROM_CODE(idx);
			ASSERT_SIZE(charcodes, idx);
			I32 v2 = AS_I32(&STACK_AND_PREV);
			I32 v1 = AS_I32(&STACK_AND_PREV);
			if (v1 > v2)
				*pc = idx;
			break;
		}
		case (JmpExtensions::kJGTUI32s):
		{
			LOCAL_UI8_FROM_CODE(idx);
			ASSERT_SIZE(charcodes, idx);
			WRD v2 = AS_WRD(&STACK_AND_PREV);
			WRD v1 = AS_WRD(&STACK_AND_PREV);
			if (v1 > v2)
				*pc = idx;
			break;
		}
		case (JmpExtensions::kJLEI32s):
		{
			LOCAL_UI8_FROM_CODE(idx);
			ASSERT_SIZE(charcodes, idx);
			I32 v2 = AS_I32(&STACK_AND_PREV);
			I32 v1 = AS_I32(&STACK_AND_PREV);
			if (v1 <= v2)
				*pc = idx;
			break;
		}
		case (JmpExtensions::kJLEUI32s):
		{
			LOCAL_UI8_FROM_CODE(idx);
			ASSERT_SIZE(charcodes, idx);
			WRD v2 = AS_WRD(&STACK_AND_PREV);
			WRD v1 = AS_WRD(&STACK_AND_PREV);
			if (v1 <= v2)
				*pc = idx;
			break;
		}
		case (JmpExtensions::kJLTI32s):
		{
			LOCAL_UI8_FROM_CODE(idx);
			ASSERT_SIZE(charcodes, idx);
			I32 v2 = AS_I32(&STACK_AND_PREV);
			I32 v1 = AS_I32(&STACK_AND_PREV);
			if (v1 < v2)
				*pc = idx;
			break;
		}
		case (JmpExtensions::kJLTUI32s):
		{
			LOCAL_UI8_FROM_CODE(idx);
			ASSERT_SIZE(charcodes, idx);
			WRD v2 = AS_WRD(&STACK_AND_PREV);
			WRD v1 = AS_WRD(&STACK_AND_PREV);
			if (v1 < v2)
				*pc = idx;
			break;
		}
	}
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
