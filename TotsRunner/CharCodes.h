#pragma once

typedef unsigned char uchar;

#define LOADS(V)\
V(LdNeg)	\
V(Ld0)		\
V(LdI8)		\
V(LdI16)	\
V(LdI32)	\

#define ARITH(V)\
V(Add)		\
V(Sub)		\
V(Mul)		\
V(Div)		\

enum CharCodes : uchar {
#define DECLARE_CHARCODE(Name) Name,
	LOADS(DECLARE_CHARCODE)
	ARITH(DECLARE_CHARCODE)
#undef DECLARE_CHARCODE	
};

#undef LOADS