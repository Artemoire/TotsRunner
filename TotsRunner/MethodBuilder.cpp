#include "MethodBuilder.h"
#include "CharCodes.h"

#define CODE(X) static_cast<uchar>(X)

vector<uchar> MethodBuilder::build()
{
	return charcodes;
}

MethodBuilder MethodBuilder::ldNeg()
{
	charcodes.push_back(CODE(CharCodes::LdNeg));
	return *this;
}

MethodBuilder MethodBuilder::ld0()
{
	charcodes.push_back(CODE(CharCodes::Ld0));
	return *this;
}

MethodBuilder MethodBuilder::ldi8(WORD i8)
{
	charcodes.push_back(CODE(CharCodes::LdI8));
	charcodes.push_back(CODE(i8));
	return *this;
}

MethodBuilder MethodBuilder::ldi16(WORD i16)
{
	charcodes.push_back(CODE(CharCodes::LdI16));
	charcodes.push_back(CODE(i16));
	charcodes.push_back(CODE(i16 >> 8));
	return *this;
}

MethodBuilder MethodBuilder::ldi32(WORD i32)
{
	charcodes.push_back(CODE(CharCodes::LdI32));
	charcodes.push_back(CODE(i32));
	charcodes.push_back(CODE(i32 >> 8));
	charcodes.push_back(CODE(i32 >> 16));
	charcodes.push_back(CODE(i32 >> 24));
	return *this;
}

MethodBuilder MethodBuilder::add()
{
	charcodes.push_back(CODE(CharCodes::Add));
	return *this;
}

MethodBuilder MethodBuilder::sub()
{
	charcodes.push_back(CODE(CharCodes::Sub));
	return *this;
}

MethodBuilder MethodBuilder::mul()
{
	charcodes.push_back(CODE(CharCodes::Mul));
	return *this;
}

MethodBuilder MethodBuilder::div()
{
	charcodes.push_back(CODE(CharCodes::Div));
	return *this;
}

#undef CODE