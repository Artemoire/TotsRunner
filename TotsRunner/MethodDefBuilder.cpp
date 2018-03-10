#include "MethodDefBuilder.h"

#define CODE(X) static_cast<UChar>(X)

starray<UChar> * MethodDefBuilder::build()
{
	WRD size = charcodes.size();
	starray<UChar> * stcodes = new starray<UChar>(size);
	for (WRD i = 0; i < size; ++i)
		stcodes->values[i] = charcodes[i];
	charcodes.clear();	
	return stcodes;
}

MethodDefBuilder MethodDefBuilder::Nop()
{
	charcodes.push_back(CODE(CharCodes::kNOP));
	return *this;
}

MethodDefBuilder MethodDefBuilder::Pop()
{
	charcodes.push_back(CODE(CharCodes::kPOP));
	return *this;
}

MethodDefBuilder MethodDefBuilder::Dup()
{
	charcodes.push_back(CODE(CharCodes::kDUP));
	return *this;
}

MethodDefBuilder MethodDefBuilder::Ret()
{
	charcodes.push_back(CODE(CharCodes::kRET));
	return *this;
}

MethodDefBuilder MethodDefBuilder::Call(WRD i32)
{
	charcodes.push_back(CODE(CharCodes::kCALL));
	charcodes.push_back(CODE(i32));
	charcodes.push_back(CODE(i32 >> 8));
	charcodes.push_back(CODE(i32 >> 16));
	charcodes.push_back(CODE(i32 >> 24));
	return *this;
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
	WRD i32 = *(WRD*)&f;
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

MethodDefBuilder MethodDefBuilder::Lvarg0()
{
	charcodes.push_back(CODE(CharCodes::kLVARG0));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Lvarg1()
{
	charcodes.push_back(CODE(CharCodes::kLVARG1));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Lvarg2()
{
	charcodes.push_back(CODE(CharCodes::kLVARG2));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Lvarg3()
{
	charcodes.push_back(CODE(CharCodes::kLVARG3));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Lvargi8(WRD v)
{
	charcodes.push_back(CODE(CharCodes::kLVARGI8));
	charcodes.push_back(CODE(v));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Lvargi16(WRD v)
{
	charcodes.push_back(CODE(CharCodes::kLVARGI16));
	charcodes.push_back(CODE(v));
	charcodes.push_back(CODE(v >> 8));
	return *this;
}

MethodDefBuilder MethodDefBuilder::Lvaargi8(WRD v)
{
	charcodes.push_back(CODE(CharCodes::kLVAARGI16));
	charcodes.push_back(CODE(v));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Lvaargi16(WRD v)
{
	charcodes.push_back(CODE(CharCodes::kLVAARGI16));
	charcodes.push_back(CODE(v));
	charcodes.push_back(CODE(v >> 8));
	return *this;
}


MethodDefBuilder MethodDefBuilder::Lvindi8()
{
	charcodes.push_back(CODE(CharCodes::kLVINDI8));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Lvindi16()
{
	charcodes.push_back(CODE(CharCodes::kLVINDI16));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Lvindi32()
{
	charcodes.push_back(CODE(CharCodes::kLVINDI32));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Lvindf32()
{
	charcodes.push_back(CODE(CharCodes::kLVINDF32));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Lvindref()
{
	charcodes.push_back(CODE(CharCodes::kLVINDREF));
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

MethodDefBuilder MethodDefBuilder::Stargi8(WRD v)
{
	charcodes.push_back(CODE(CharCodes::kSTARGI8));
	charcodes.push_back(CODE(v));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Stargi16(WRD v)
{
	charcodes.push_back(CODE(CharCodes::kSTARGI16));
	charcodes.push_back(CODE(v));
	charcodes.push_back(CODE(v >> 8));
	return *this;
}

MethodDefBuilder MethodDefBuilder::Stindi8(WRD v)
{
	Lvi8(v);
	charcodes.push_back(CODE(CharCodes::kSTINDI8));	
	return *this;
}
MethodDefBuilder MethodDefBuilder::Stindi16(WRD v)
{
	Lvi16(v);
	charcodes.push_back(CODE(CharCodes::kSTINDI16));	
	return *this;
}
MethodDefBuilder MethodDefBuilder::Stindi32()
{
	charcodes.push_back(CODE(CharCodes::kSTINDI32));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Stindi32(WRD v)
{
	Lvi32(v);
	charcodes.push_back(CODE(CharCodes::kSTINDI32));
	return *this;
}
MethodDefBuilder MethodDefBuilder::Stindf32(Float f)
{
	Lvf32(f);
	charcodes.push_back(CODE(CharCodes::kSTINDF32));	
	return *this;
}
MethodDefBuilder MethodDefBuilder::Stindref(WRD v)
{
	Lvi32(v);
	charcodes.push_back(CODE(CharCodes::kSTINDI32));	
	return *this;
}

MethodDefBuilder MethodDefBuilder::Addi32()
{
	charcodes.push_back(CODE(CharCodes::kOP));
	charcodes.push_back(CODE(OpsExtensions::kADD_I32));
	return *this;
}

MethodDefBuilder MethodDefBuilder::Add(WRD v)
{
	Lvi8(v);

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
MethodDefBuilder MethodDefBuilder::Muli32()
{
	charcodes.push_back(CODE(CharCodes::kOP));
	charcodes.push_back(CODE(OpsExtensions::kMUL_I32));
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

MethodDefBuilder MethodDefBuilder::Jmps(WRD v)
{
	charcodes.push_back(CODE(CharCodes::kJMPOP));
	charcodes.push_back(CODE(JmpExtensions::kJMPs));
	charcodes.push_back(CODE(v));
	return *this;
}

MethodDefBuilder MethodDefBuilder::Jeq32s(WRD v)
{
	charcodes.push_back(CODE(CharCodes::kJMPOP));
	charcodes.push_back(CODE(JmpExtensions::kJEQ32s));
	charcodes.push_back(CODE(v));
	return *this;
}

MethodDefBuilder MethodDefBuilder::Jne32s(WRD v)
{
	charcodes.push_back(CODE(CharCodes::kJMPOP));
	charcodes.push_back(CODE(JmpExtensions::kJNE32s));
	charcodes.push_back(CODE(v));
	return *this;
}

MethodDefBuilder MethodDefBuilder::Jgei32s(WRD v)
{
	charcodes.push_back(CODE(CharCodes::kJMPOP));
	charcodes.push_back(CODE(JmpExtensions::kJGEI32s));
	charcodes.push_back(CODE(v));
	return *this;
}

MethodDefBuilder MethodDefBuilder::Jgeui32s(WRD v)
{
	charcodes.push_back(CODE(CharCodes::kJMPOP));
	charcodes.push_back(CODE(JmpExtensions::kJGEUI32s));
	charcodes.push_back(CODE(v));
	return *this;
}

MethodDefBuilder MethodDefBuilder::jgti32s(WRD v)
{
	charcodes.push_back(CODE(CharCodes::kJMPOP));
	charcodes.push_back(CODE(JmpExtensions::kJGTI32s));
	charcodes.push_back(CODE(v));
	return *this;
}

MethodDefBuilder MethodDefBuilder::jgtui32s(WRD v)
{
	charcodes.push_back(CODE(CharCodes::kJMPOP));
	charcodes.push_back(CODE(JmpExtensions::kJGTUI32s));
	charcodes.push_back(CODE(v));
	return *this;
}

MethodDefBuilder MethodDefBuilder::jlei32s(WRD v)
{
	charcodes.push_back(CODE(CharCodes::kJMPOP));
	charcodes.push_back(CODE(JmpExtensions::kJLEI32s));
	charcodes.push_back(CODE(v));
	return *this;
}

MethodDefBuilder MethodDefBuilder::jleui32s(WRD v)
{
	charcodes.push_back(CODE(CharCodes::kJMPOP));
	charcodes.push_back(CODE(JmpExtensions::kJLEUI32s));
	charcodes.push_back(CODE(v));
	return *this;
}

MethodDefBuilder MethodDefBuilder::jlti32s(WRD v)
{
	charcodes.push_back(CODE(CharCodes::kJMPOP));
	charcodes.push_back(CODE(JmpExtensions::kJLTI32s));
	charcodes.push_back(CODE(v));
	return *this;
}

MethodDefBuilder MethodDefBuilder::jltui32s(WRD v)
{
	charcodes.push_back(CODE(CharCodes::kJMPOP));
	charcodes.push_back(CODE(JmpExtensions::kJLTUI32s));
	charcodes.push_back(CODE(v));
	return *this;
}

MethodDefBuilder MethodDefBuilder::Cmp(CmpExtensions op)
{
	charcodes.push_back(CODE(CharCodes::kCMP));
	charcodes.push_back(CODE(op));
	return *this;
}


#undef CODE