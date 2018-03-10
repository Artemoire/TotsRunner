#pragma once

#include "defs.h"

#define BASE(V)	\
V(kNOP)			\
V(kPOP)			\

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


#define STORES(V)\
V(kSTLOC0)	 	 \
V(kSTLOC1)	  	 \
V(kSTLOC2)		 \
V(kSTLOC3)		 \
V(kSTLOCI8)		 \
V(kSTLOCI16)	 \


#define OPS(V)	\
V(kOP)			\
V(kJMPOP)		\
V(kCMP)		\

#define DECLARE_CHARCODE(Name) Name,

enum CharCodes : UChar
{
	BASE(DECLARE_CHARCODE)
#undef BASE
	LOADS(DECLARE_CHARCODE)
#undef LOADS
	STORES(DECLARE_CHARCODE)
#undef STORES
	OPS(DECLARE_CHARCODE)
#undef OPS
};


#define OPSX(V) \
V(kADD_I32)		\
V(kSUB_I32)		\
V(kMUL_I32)		\
V(kDIV_I32)		\
V(kADD_F32)		\
V(kSUB_F32)		\
V(kMUL_F32)		\
V(kDIV_F32)		\
V(kAND)			\
V(kOR)			\
V(kXOR)			\
V(kSHR32)		\
V(kSHL32)		\

enum OpsExtensions : UChar
{
	OPSX(DECLARE_CHARCODE)
#undef OPSX
};

#define JMPSX(V)\
V(kJMP)			\
V(kJEQ32)		\
V(kJNE32)		\
V(kJGEI32)		\
V(kJGEUI32)		\
V(kJGTI32)		\
V(kJGTUI32)		\
V(kJLEI32)		\
V(kJLEUI32)		\
V(kJLTI32)		\
V(kJLTUI32)		\
\
V(kJMPs)		\
V(kJEQ32s)		\
V(kJNE32s)		\
V(kJGEI32s)		\
V(kJGEUI32s)	\
V(kJGTI32s)		\
V(kJGTUI32s)	\
V(kJLEI32s)		\
V(kJLEUI32s)	\
V(kJLTI32s)		\
V(kJLTUI32s)	\

enum JmpExtensions : UChar
{
	JMPSX(DECLARE_CHARCODE)
#undef JMPSX
};

#define CMPSX(V)\
V(kCEQ32)		\
V(kCNE32)		\
V(kCGEI32)		\
V(kCGEUI32)		\
V(kCGTI32)		\
V(kCGTUI32)		\
V(kCLEI32)		\
V(kCLEUI32)		\
V(kCLTI32)		\
V(kCLTUI32)		\

enum CmpExtensions : UChar
{
	CMPSX(DECLARE_CHARCODE)
#undef CMPSX
};

#undef DECLARE_CHARCODE	