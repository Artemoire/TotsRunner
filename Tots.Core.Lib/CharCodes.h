#pragma once

#include "global_defs.h"

#define BASE(V)	\
V(kNOP)			\
V(kPOP)			\
V(kDUP)			\
V(kRET)			\
V(kCALL)		\

#define LOADS(V)\
V(kLCNEG1)		\
V(kLC0)			\
V(kLC1)			\
V(kLC2)			\
V(kLC3)			\
V(kLVI8)		\
V(kLVI16)		\
V(kLVI32)		\
V(kLVF32)		\
V(kLVLOC0)		\
V(kLVLOC1)		\
V(kLVLOC2)		\
V(kLVLOC3)		\
V(kLVLOCI8)		\
V(kLVLOCI16)	\
V(kLVALOCI16)	\
V(kLVARG0)		\
V(kLVARG1)		\
V(kLVARG2)		\
V(kLVARG3)		\
V(kLVARGI8)		\
V(kLVARGI16)	\
V(kLVAARGI8)	\
V(kLVAARGI16)	\
V(kLVINDI8)		\
V(kLVINDI16)	\
V(kLVINDI32)	\
V(kLVINDF32)	\
V(kLVINDREF)	\


#define STORES(V)\
V(kSTLOC0)	 	 \
V(kSTLOC1)	  	 \
V(kSTLOC2)		 \
V(kSTLOC3)		 \
V(kSTLOCI8)		 \
V(kSTLOCI16)	 \
V(kSTARGI8)		 \
V(kSTARGI16)	 \
V(kSTINDI8)		 \
V(kSTINDI16)	 \
V(kSTINDI32)	 \
V(kSTINDF32)	 \
V(kSTINDREF)	 \

#define ARITH(V) \
V(kADD)			 \
V(kSUB)			 \
V(kDIV)			 \
V(kMUL)			 \
V(kREM)			 \

#define BINOPS(V)	\
V(kAND)				\
V(kOR)				\
V(kXOR)				\
V(kSHR)				\
V(kSHL)				\

#define JMPS(V)	\
V(kJMP)			\
V(kJTRUE)		\
V(kJFALSE)		\
V(kJEQ)			\
V(kJNE)			\
V(kJGE)			\
V(kJGT)			\
V(kJLE)			\
V(kJLT)			\
\
V(kJMPs)		\
V(kJTRUEs)		\
V(kJFALSEs)		\
V(kJEQs)		\
V(kJNEs)		\
V(kJGEs)		\
V(kJGTs)		\
V(kJLEs)		\
V(kJLTs)		\

#define CMPS(V)	\
V(kCEQ)			\
V(kCNE)			\
V(kCGE)			\
V(kCGT)			\
V(kCLE)			\
V(kCLT)			\

namespace Tots
{
	namespace Core
	{
		namespace Execution
		{
			// todo dont undef for swtich generatiin
			enum CharCodes : UChar
			{
				BASE(DECLARE_ENUM)
#undef BASE
				LOADS(DECLARE_ENUM)
#undef LOADS
				STORES(DECLARE_ENUM)
#undef STORES
				ARITH(DECLARE_ENUM)
#undef ARITH
				BINOPS(DECLARE_ENUM)
#undef BINOPS
				JMPS(DECLARE_ENUM)
#undef JMPS
				CMPS(DECLARE_ENUM)
#undef CMPS
			};			
		}
	}
}