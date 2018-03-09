#pragma once
#include <vector>
#include "defs.h"

using namespace std;

class MethodDefBuilder {
	vector<UChar> charcodes;

public:
	starray<UChar> * build();

	MethodDefBuilder LVI_1();
	MethodDefBuilder LVI0();
	MethodDefBuilder LVI8(WRD);
	MethodDefBuilder LVI16(WRD);
	MethodDefBuilder LVI32(WRD);
	MethodDefBuilder LVF32(Float);
	MethodDefBuilder add(WRD);
	MethodDefBuilder add(Float);
	MethodDefBuilder sub(WRD);
	MethodDefBuilder sub(Float);	
	MethodDefBuilder mul(WRD);
	MethodDefBuilder mul(Float);
	MethodDefBuilder div(WRD);
	MethodDefBuilder div(Float);
	MethodDefBuilder And(WRD);
	MethodDefBuilder Or(WRD);
	MethodDefBuilder Xor(WRD);
	MethodDefBuilder Shr32(WRD);
	MethodDefBuilder Shl32(WRD);
};