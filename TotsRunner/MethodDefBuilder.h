#pragma once
#include <vector>
#include "defs.h"
#include "CharCodes.h"

using namespace std;

class MethodDefBuilder {
	vector<UChar> charcodes;

public:
	starray<UChar> * build();

	MethodDefBuilder Nop();
	MethodDefBuilder Pop();
	MethodDefBuilder Dup();	
	MethodDefBuilder Ret();
	MethodDefBuilder Call(WRD);

	MethodDefBuilder Lcneg1();
	MethodDefBuilder Lc0();
	MethodDefBuilder Lc1();
	MethodDefBuilder Lc2();
	MethodDefBuilder Lc3();
	MethodDefBuilder Lvi8(WRD);
	MethodDefBuilder Lvi16(WRD);
	MethodDefBuilder Lvi32(WRD);
	MethodDefBuilder Lvf32(Float);
	MethodDefBuilder Lvloc0();
	MethodDefBuilder Lvloc1();
	MethodDefBuilder Lvloc2();
	MethodDefBuilder Lvloc3();
	MethodDefBuilder Lvloci8(WRD);
	MethodDefBuilder Lvloci16(WRD);	
	MethodDefBuilder Lvaloci16(WRD);

	MethodDefBuilder Lvarg0();
	MethodDefBuilder Lvarg1();
	MethodDefBuilder Lvarg2();
	MethodDefBuilder Lvarg3();
	MethodDefBuilder Lvargi8(WRD);
	MethodDefBuilder Lvargi16(WRD);
	MethodDefBuilder Lvaargi8(WRD);
	MethodDefBuilder Lvaargi16(WRD);

	MethodDefBuilder Lvindi8();
	MethodDefBuilder Lvindi16();
	MethodDefBuilder Lvindi32();
	MethodDefBuilder Lvindf32();
	MethodDefBuilder Lvindref();

	MethodDefBuilder Stloc0();
	MethodDefBuilder Stloc1();
	MethodDefBuilder Stloc2();
	MethodDefBuilder Stloc3();
	MethodDefBuilder Stloci8(WRD);
	MethodDefBuilder Stloci16(WRD);

	MethodDefBuilder Stargi8(WRD);
	MethodDefBuilder Stargi16(WRD);

	MethodDefBuilder Stindi8(WRD);
	MethodDefBuilder Stindi16(WRD);
	MethodDefBuilder Stindi32();
	MethodDefBuilder Stindi32(WRD);
	MethodDefBuilder Stindf32(Float);
	MethodDefBuilder Stindref(WRD);

	MethodDefBuilder Addi32();
	MethodDefBuilder Add(WRD);
	MethodDefBuilder Add(Float);
	MethodDefBuilder Sub(WRD);
	MethodDefBuilder Sub(Float);	
	MethodDefBuilder Muli32();
	MethodDefBuilder Mul(WRD);
	MethodDefBuilder Mul(Float);
	MethodDefBuilder Div(WRD);
	MethodDefBuilder Div(Float);
	MethodDefBuilder And(WRD);
	MethodDefBuilder Or(WRD);
	MethodDefBuilder Xor(WRD);
	MethodDefBuilder Shr32(WRD);
	MethodDefBuilder Shl32(WRD);

	MethodDefBuilder Jmps(WRD);
	MethodDefBuilder Jeq32s(WRD);
	MethodDefBuilder Jne32s(WRD);
	MethodDefBuilder Jgei32s(WRD);
	MethodDefBuilder Jgeui32s(WRD);
	MethodDefBuilder jgti32s(WRD);
	MethodDefBuilder jgtui32s(WRD);
	MethodDefBuilder jlei32s(WRD);
	MethodDefBuilder jleui32s(WRD);
	MethodDefBuilder jlti32s(WRD);
	MethodDefBuilder jltui32s(WRD);

	MethodDefBuilder Cmp(CmpExtensions);
};