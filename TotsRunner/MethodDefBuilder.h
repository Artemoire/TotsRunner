#pragma once
#include <vector>
#include "defs.h"

using namespace std;

class MethodDefBuilder {
	vector<UChar> charcodes;

public:
	vector<UChar> build();

	MethodDefBuilder LVI_1();
	MethodDefBuilder LVI0();
	MethodDefBuilder LVI8(WORD);
	MethodDefBuilder LVI16(WORD);
	MethodDefBuilder LVI32(WORD);
	MethodDefBuilder LVF(Float);
	MethodDefBuilder add();
	MethodDefBuilder sub();
	MethodDefBuilder mul();
	MethodDefBuilder div();

};