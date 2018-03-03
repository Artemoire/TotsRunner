#include "CharCodeBuilder.h"
#include "CharCodes.h"

#define CODE(X) static_cast<uchar>(X)

vector<uchar> CharCodeBuilder::build()
{
	return charcodes;
}

CharCodeBuilder CharCodeBuilder::ldNeg()
{
	charcodes.push_back(CODE(CharCodes::LdNeg));
	return *this;
}

CharCodeBuilder CharCodeBuilder::ld0()
{
	charcodes.push_back(CODE(CharCodes::Ld0));
	return *this;
}

CharCodeBuilder CharCodeBuilder::ldi8(WORD i8)
{
	charcodes.push_back(CODE(CharCodes::LdI8));
	charcodes.push_back(CODE(i8));
	return *this;
}

CharCodeBuilder CharCodeBuilder::ldi16(WORD i16)
{
	charcodes.push_back(CODE(CharCodes::LdI16));
	charcodes.push_back(CODE(i16));
	charcodes.push_back(CODE(i16 >> 8));
	return *this;
}

CharCodeBuilder CharCodeBuilder::ldi32(WORD i32)
{
	charcodes.push_back(CODE(CharCodes::LdI32));
	charcodes.push_back(CODE(i32));
	charcodes.push_back(CODE(i32 >> 8));
	charcodes.push_back(CODE(i32 >> 16));
	charcodes.push_back(CODE(i32 >> 24));
	return *this;
}

CharCodeBuilder CharCodeBuilder::add()
{
	charcodes.push_back(CODE(CharCodes::Add));
	return *this;
}

CharCodeBuilder CharCodeBuilder::sub()
{
	charcodes.push_back(CODE(CharCodes::Sub));
	return *this;
}

CharCodeBuilder CharCodeBuilder::mul()
{
	charcodes.push_back(CODE(CharCodes::Mul));
	return *this;
}

CharCodeBuilder CharCodeBuilder::div()
{
	charcodes.push_back(CODE(CharCodes::Div));
	return *this;
}

#undef CODE