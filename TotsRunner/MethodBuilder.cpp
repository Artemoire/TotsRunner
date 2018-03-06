#include "MethodBuilder.h"
#include "CharCodes.h"

#define CODE(X) static_cast<UCHAR>(X)

vector<UCHAR> MethodBuilder::build()
{
	return charcodes;
}

MethodBuilder MethodBuilder::LVI_1()
{
	charcodes.push_back(CODE(CharCodes::kLVI_1));
	return *this;
}

MethodBuilder MethodBuilder::LVI0()
{
	charcodes.push_back(CODE(CharCodes::kLVI0));
	return *this;
}

MethodBuilder MethodBuilder::LVI8(WORD i8)
{
	charcodes.push_back(CODE(CharCodes::kLVI8));
	charcodes.push_back(CODE(i8));
	return *this;
}

MethodBuilder MethodBuilder::LVI16(WORD i16)
{
	charcodes.push_back(CODE(CharCodes::kLVI16));
	charcodes.push_back(CODE(i16));
	charcodes.push_back(CODE(i16 >> 8));
	return *this;
}

MethodBuilder MethodBuilder::LVI32(WORD i32)
{
	charcodes.push_back(CODE(CharCodes::kLVI32));
	charcodes.push_back(CODE(i32));
	charcodes.push_back(CODE(i32 >> 8));
	charcodes.push_back(CODE(i32 >> 16));
	charcodes.push_back(CODE(i32 >> 24));
	return *this;
}

MethodBuilder MethodBuilder::LVF(FLOAT f)
{
	WORD i32 = *(WORD*)&f;
	charcodes.push_back(CODE(CharCodes::kLVF));
	charcodes.push_back(CODE(i32));
	charcodes.push_back(CODE(i32 >> 8));
	charcodes.push_back(CODE(i32 >> 16));
	charcodes.push_back(CODE(i32 >> 24));
	return *this;
}

MethodBuilder MethodBuilder::add()
{
	charcodes.push_back(CODE(CharCodes::kADD));
	return *this;
}

MethodBuilder MethodBuilder::sub()
{
	charcodes.push_back(CODE(CharCodes::kSUB));
	return *this;
}

MethodBuilder MethodBuilder::mul()
{
	charcodes.push_back(CODE(CharCodes::kMUL));
	return *this;
}

MethodBuilder MethodBuilder::div()
{
	charcodes.push_back(CODE(CharCodes::kDIV));
	return *this;
}

#undef CODE