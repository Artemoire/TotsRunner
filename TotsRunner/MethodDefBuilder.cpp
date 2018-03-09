#include "MethodDefBuilder.h"
#include "CharCodes.h"

#define CODE(X) static_cast<UChar>(X)

starray<UChar> * MethodDefBuilder::build()
{
	WRD size = charcodes.size();
	starray<UChar> * stcodes = new starray<UChar>(size);
	for (WRD i = 0; i < size; ++i)
		stcodes->values[i] = charcodes[i];
	return stcodes;
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

MethodDefBuilder MethodDefBuilder::LVI8(WRD i8)
{
	charcodes.push_back(CODE(CharCodes::kLVI8));
	charcodes.push_back(CODE(i8));
	return *this;
}

MethodDefBuilder MethodDefBuilder::LVI16(WRD i16)
{
	charcodes.push_back(CODE(CharCodes::kLVI16));
	charcodes.push_back(CODE(i16));
	charcodes.push_back(CODE(i16 >> 8));
	return *this;
}

MethodDefBuilder MethodDefBuilder::LVI32(WRD i32)
{
	charcodes.push_back(CODE(CharCodes::kLVI32));
	charcodes.push_back(CODE(i32));
	charcodes.push_back(CODE(i32 >> 8));
	charcodes.push_back(CODE(i32 >> 16));
	charcodes.push_back(CODE(i32 >> 24));
	return *this;
}

MethodDefBuilder MethodDefBuilder::LVF32(Float f)
{
	DWRD i32 = *(DWRD*)&f;
	charcodes.push_back(CODE(CharCodes::kLVF32));
	charcodes.push_back(CODE(i32));
	charcodes.push_back(CODE(i32 >> 8));
	charcodes.push_back(CODE(i32 >> 16));
	charcodes.push_back(CODE(i32 >> 24));
	return *this;
}
MethodDefBuilder MethodDefBuilder::add(WRD v)
{
	LVI32(v);

	charcodes.push_back(CODE(CharCodes::kOP));
	charcodes.push_back(CODE(OpsExtensions::kADD_I32));
	return *this;
}
MethodDefBuilder MethodDefBuilder::add(Float v)
{
	LVF32(v);

	charcodes.push_back(CODE(CharCodes::kOP));
	charcodes.push_back(CODE(OpsExtensions::kADD_F32));
	return *this;
}
MethodDefBuilder MethodDefBuilder::sub(WRD v)
{
	LVI32(v);

	charcodes.push_back(CODE(CharCodes::kOP));
	charcodes.push_back(CODE(OpsExtensions::kSUB_I32));
	return *this;
}
MethodDefBuilder MethodDefBuilder::sub(Float v)
{
	LVF32(v);

	charcodes.push_back(CODE(CharCodes::kOP));
	charcodes.push_back(CODE(OpsExtensions::kSUB_F32));
	return *this;
}
MethodDefBuilder MethodDefBuilder::mul(WRD v)
{
	LVI32(v);

	charcodes.push_back(CODE(CharCodes::kOP));
	charcodes.push_back(CODE(OpsExtensions::kMUL_I32));
	return *this;
}
MethodDefBuilder MethodDefBuilder::mul(Float v)
{
	LVF32(v);

	charcodes.push_back(CODE(CharCodes::kOP));
	charcodes.push_back(CODE(OpsExtensions::kMUL_F32));
	return *this;
}
MethodDefBuilder MethodDefBuilder::div(WRD v)
{
	LVI32(v);

	charcodes.push_back(CODE(CharCodes::kOP));
	charcodes.push_back(CODE(OpsExtensions::kDIV_I32));
	return *this;
}
MethodDefBuilder MethodDefBuilder::div(Float v)
{
	LVF32(v);

	charcodes.push_back(CODE(CharCodes::kOP));
	charcodes.push_back(CODE(OpsExtensions::kDIV_F32));
	return *this;
}

MethodDefBuilder MethodDefBuilder::And(WRD v)
{
	LVI32(v);

	charcodes.push_back(CODE(CharCodes::kOP));
	charcodes.push_back(CODE(OpsExtensions::kAND));
	return *this;
}

MethodDefBuilder MethodDefBuilder::Or(WRD v)
{
	LVI32(v);

	charcodes.push_back(CODE(CharCodes::kOP));
	charcodes.push_back(CODE(OpsExtensions::kOR));
	return *this;
}

MethodDefBuilder MethodDefBuilder::Xor(WRD v)
{
	LVI32(v);

	charcodes.push_back(CODE(CharCodes::kOP));
	charcodes.push_back(CODE(OpsExtensions::kXOR));
	return *this;
}

MethodDefBuilder MethodDefBuilder::Shr32(WRD v)
{
	LVI32(v);

	charcodes.push_back(CODE(CharCodes::kOP));
	charcodes.push_back(CODE(OpsExtensions::kSHR32));
	return *this;
}

MethodDefBuilder MethodDefBuilder::Shl32(WRD v)
{
	LVI32(v);

	charcodes.push_back(CODE(CharCodes::kOP));
	charcodes.push_back(CODE(OpsExtensions::kSHL32));
	return *this;
}


#undef CODE