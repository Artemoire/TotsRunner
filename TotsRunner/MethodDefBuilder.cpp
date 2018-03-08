#include "MethodDefBuilder.h"
#include "CharCodes.h"

#define CODE(X) static_cast<UChar>(X)

vector<UChar> MethodDefBuilder::build()
{
	return charcodes;
}

MethodDefBuilder MethodDefBuilder::LVI_1()
{
	charcodes.push_back(CODE(CharCodes::kLVI_1));
	return *this;
}

MethodDefBuilder MethodDefBuilder::LVI0()
{
	charcodes.push_back(CODE(CharCodes::kLVI0));
	return *this;
}

MethodDefBuilder MethodDefBuilder::LVI8(WORD i8)
{
	charcodes.push_back(CODE(CharCodes::kLVI8));
	charcodes.push_back(CODE(i8));
	return *this;
}

MethodDefBuilder MethodDefBuilder::LVI16(WORD i16)
{
	charcodes.push_back(CODE(CharCodes::kLVI16));
	charcodes.push_back(CODE(i16));
	charcodes.push_back(CODE(i16 >> 8));
	return *this;
}

MethodDefBuilder MethodDefBuilder::LVI32(WORD i32)
{
	charcodes.push_back(CODE(CharCodes::kLVI32));
	charcodes.push_back(CODE(i32));
	charcodes.push_back(CODE(i32 >> 8));
	charcodes.push_back(CODE(i32 >> 16));
	charcodes.push_back(CODE(i32 >> 24));
	return *this;
}

MethodDefBuilder MethodDefBuilder::LVF(Float f)
{
	WORD i32 = *(WORD*)&f;
	charcodes.push_back(CODE(CharCodes::kLVF));
	charcodes.push_back(CODE(i32));
	charcodes.push_back(CODE(i32 >> 8));
	charcodes.push_back(CODE(i32 >> 16));
	charcodes.push_back(CODE(i32 >> 24));
	return *this;
}

MethodDefBuilder MethodDefBuilder::add()
{
	charcodes.push_back(CODE(CharCodes::kADD));
	return *this;
}

MethodDefBuilder MethodDefBuilder::sub()
{
	charcodes.push_back(CODE(CharCodes::kSUB));
	return *this;
}

MethodDefBuilder MethodDefBuilder::mul()
{
	charcodes.push_back(CODE(CharCodes::kMUL));
	return *this;
}

MethodDefBuilder MethodDefBuilder::div()
{
	charcodes.push_back(CODE(CharCodes::kDIV));
	return *this;
}

#undef CODE