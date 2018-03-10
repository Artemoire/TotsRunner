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

MethodDefBuilder MethodDefBuilder::Lcneg1()
{
	charcodes.push_back(CODE(CharCodes::kLCNEG1));
	return *this;
}

MethodDefBuilder MethodDefBuilder::Lc0()
{
	charcodes.push_back(CODE(CharCodes::kLC0));
	return *this;
}

MethodDefBuilder MethodDefBuilder::Lc1()
{
	charcodes.push_back(CODE(CharCodes::kLC1));
	return *this;
}

MethodDefBuilder MethodDefBuilder::Lc2()
{
	charcodes.push_back(CODE(CharCodes::kLC2));
	return *this;
}

MethodDefBuilder MethodDefBuilder::Lc3()
{
	charcodes.push_back(CODE(CharCodes::kLC3));
	return *this;
}

MethodDefBuilder MethodDefBuilder::Lvi8(WRD i8)
{
	charcodes.push_back(CODE(CharCodes::kLVI8));
	charcodes.push_back(CODE(i8));
	return *this;
}

MethodDefBuilder MethodDefBuilder::Lvi16(WRD i16)
{
	charcodes.push_back(CODE(CharCodes::kLVI16));
	charcodes.push_back(CODE(i16));
	charcodes.push_back(CODE(i16 >> 8));
	return *this;
}

MethodDefBuilder MethodDefBuilder::Lvi32(WRD i32)
{
	charcodes.push_back(CODE(CharCodes::kLVI32));
	charcodes.push_back(CODE(i32));
	charcodes.push_back(CODE(i32 >> 8));
	charcodes.push_back(CODE(i32 >> 16));
	charcodes.push_back(CODE(i32 >> 24));
	return *this;
}

MethodDefBuilder MethodDefBuilder::Lvf32(Float f)
{
	DWRD i32 = *(DWRD*)&f;
	charcodes.push_back(CODE(CharCodes::kLVF32));
	charcodes.push_back(CODE(i32));
	charcodes.push_back(CODE(i32 >> 8));
	charcodes.push_back(CODE(i32 >> 16));
	charcodes.push_back(CODE(i32 >> 24));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Lvloc0()
{
	charcodes.push_back(CODE(CharCodes::kLVLOC0));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Lvloc1()
{
	charcodes.push_back(CODE(CharCodes::kLVLOC1));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Lvloc2()
{
	charcodes.push_back(CODE(CharCodes::kLVLOC2));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Lvloc3()
{
	charcodes.push_back(CODE(CharCodes::kLVLOC3));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Lvloci8(WRD v)
{
	charcodes.push_back(CODE(CharCodes::kLVLOCI8));
	charcodes.push_back(CODE(v));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Lvloci16(WRD v)
{
	charcodes.push_back(CODE(CharCodes::kLVLOCI16));
	charcodes.push_back(CODE(v));
	charcodes.push_back(CODE(v >> 8));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Lvaloci16(WRD v)
{
	charcodes.push_back(CODE(CharCodes::kLVALOCI16));
	charcodes.push_back(CODE(v));
	charcodes.push_back(CODE(v >> 8));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Stloc0()
{
	charcodes.push_back(CODE(CharCodes::kSTLOC0));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Stloc1()
{
	charcodes.push_back(CODE(CharCodes::kSTLOC1));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Stloc2()
{
	charcodes.push_back(CODE(CharCodes::kSTLOC2));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Stloc3()
{
	charcodes.push_back(CODE(CharCodes::kSTLOC3));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Stloci8(WRD v)
{
	charcodes.push_back(CODE(CharCodes::kSTLOCI8));
	charcodes.push_back(CODE(v));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Stloci16(WRD v)
{
	charcodes.push_back(CODE(CharCodes::kSTLOCI16));
	charcodes.push_back(CODE(v));
	charcodes.push_back(CODE(v >> 8));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Add(WRD v)
{
	Lvi32(v);

	charcodes.push_back(CODE(CharCodes::kOP));
	charcodes.push_back(CODE(OpsExtensions::kADD_I32));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Add(Float v)
{
	Lvf32(v);

	charcodes.push_back(CODE(CharCodes::kOP));
	charcodes.push_back(CODE(OpsExtensions::kADD_F32));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Sub(WRD v)
{
	Lvi32(v);

	charcodes.push_back(CODE(CharCodes::kOP));
	charcodes.push_back(CODE(OpsExtensions::kSUB_I32));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Sub(Float v)
{
	Lvf32(v);

	charcodes.push_back(CODE(CharCodes::kOP));
	charcodes.push_back(CODE(OpsExtensions::kSUB_F32));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Mul(WRD v)
{
	Lvi32(v);

	charcodes.push_back(CODE(CharCodes::kOP));
	charcodes.push_back(CODE(OpsExtensions::kMUL_I32));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Mul(Float v)
{
	Lvf32(v);

	charcodes.push_back(CODE(CharCodes::kOP));
	charcodes.push_back(CODE(OpsExtensions::kMUL_F32));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Div(WRD v)
{
	Lvi32(v);

	charcodes.push_back(CODE(CharCodes::kOP));
	charcodes.push_back(CODE(OpsExtensions::kDIV_I32));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Div(Float v)
{
	Lvf32(v);

	charcodes.push_back(CODE(CharCodes::kOP));
	charcodes.push_back(CODE(OpsExtensions::kDIV_F32));
	return *this;
}

MethodDefBuilder MethodDefBuilder::And(WRD v)
{
	Lvi32(v);

	charcodes.push_back(CODE(CharCodes::kOP));
	charcodes.push_back(CODE(OpsExtensions::kAND));
	return *this;
}

MethodDefBuilder MethodDefBuilder::Or(WRD v)
{
	Lvi32(v);

	charcodes.push_back(CODE(CharCodes::kOP));
	charcodes.push_back(CODE(OpsExtensions::kOR));
	return *this;
}

MethodDefBuilder MethodDefBuilder::Xor(WRD v)
{
	Lvi32(v);

	charcodes.push_back(CODE(CharCodes::kOP));
	charcodes.push_back(CODE(OpsExtensions::kXOR));
	return *this;
}

MethodDefBuilder MethodDefBuilder::Shr32(WRD v)
{
	Lvi32(v);

	charcodes.push_back(CODE(CharCodes::kOP));
	charcodes.push_back(CODE(OpsExtensions::kSHR32));
	return *this;
}

MethodDefBuilder MethodDefBuilder::Shl32(WRD v)
{
	Lvi32(v);

	charcodes.push_back(CODE(CharCodes::kOP));
	charcodes.push_back(CODE(OpsExtensions::kSHL32));
	return *this;
}


#undef CODE