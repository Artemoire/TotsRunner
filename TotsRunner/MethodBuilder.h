#pragma once
#include <vector>
#include "defs.h"

using namespace std;

class MethodBuilder {
	vector<uchar> charcodes;

public:
	vector<uchar> build();

	MethodBuilder ldNeg();
	MethodBuilder ld0();
	MethodBuilder ldi8(WORD);
	MethodBuilder ldi16(WORD);
	MethodBuilder ldi32(WORD);
	MethodBuilder add();
	MethodBuilder sub();
	MethodBuilder mul();
	MethodBuilder div();

};