#pragma once

#include "defs.h"

#define LOADS(V)\
V(kLVI_1)	\
V(kLVI0)		\
V(kLVI8)		\
V(kLVI16)	\
V(kLVI32)	\
V(kLVF)		\

#define ARITH(V)\
V(kADD)		\
V(kSUB)		\
V(kMUL)		\
V(kDIV)		\

enum CharCodes : UChar {
#define DECLARE_CHARCODE(Name) Name,
	LOADS(DECLARE_CHARCODE)
	ARITH(DECLARE_CHARCODE)
#undef DECLARE_CHARCODE	
};

#undef LOADS
#undef ARITH