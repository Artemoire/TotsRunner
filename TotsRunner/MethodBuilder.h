#pragma once
#include <vector>
#include "defs.h"

using namespace std;

class MethodBuilder {
	vector<UCHAR> charcodes;

public:
	vector<UCHAR> build();

	MethodBuilder LVI_1();
	MethodBuilder LVI0();
	MethodBuilder LVI8(WORD);
	MethodBuilder LVI16(WORD);
	MethodBuilder LVI32(WORD);
	MethodBuilder LVF(FLOAT);
	MethodBuilder add();
	MethodBuilder sub();
	MethodBuilder mul();
	MethodBuilder div();

};