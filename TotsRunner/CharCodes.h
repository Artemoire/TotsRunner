#pragma once

#include "defs.h"

#define LOADS(V)\
V(kLVI_1)	\
V(kLVI0)	\
V(kLVI8)	\
V(kLVI16)	\
V(kLVI32)	\
V(kLVF32)	\

#define OPS(V)\
V(kOP)	\

#define DECLARE_CHARCODE(Name) Name,

enum CharCodes : UChar
{
	LOADS(DECLARE_CHARCODE)
	OPS(DECLARE_CHARCODE)
};

#undef LOADS
#undef MATH

#define OPSX(V)\
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
};

#undef DECLARE_CHARCODE	
#undef MATHX