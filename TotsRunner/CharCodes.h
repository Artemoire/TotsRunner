#pragma once

#include "defs.h"

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

#define JMPS(V)\
V(kJEQ)			\
V(kJEQs)		\
V(kJNE)			\
V(kJNEs)		\
\
V(kJGEI32)		\
V(kJGEUI32)		\
V(kJGEI32s)		\
V(kJGEUI32s)	\
\
V(kJGTI32)		\
V(kJGTUI32)		\
V(kJGTI32s)		\
V(kJGTUI32s)	\
\
V(kJLEI32)		\
V(kJLEUI32)		\
V(kJLEI32s)		\
V(kJLEUI32s)	\
\
V(kJLTI32)		\
V(kJLTUI32)		\
V(kJLTI32s)		\
V(kJLTUI32s)	\


#define DECLARE_CHARCODE(Name) Name,

enum CharCodes : UChar
{
	LOADS(DECLARE_CHARCODE)
#undef LOADS
	STORES(DECLARE_CHARCODE)
#undef STORES
	OPS(DECLARE_CHARCODE)
#undef OPS
	JMPS(DECLARE_CHARCODE)
#undef JMPS
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

#undef DECLARE_CHARCODE	