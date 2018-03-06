#pragma once

#include <vector>
#include "defs.h"

using namespace std;

class TotsRunner {

	vector<uchar> charCodeArray;
	vector<WORD> stack;
	WORD pc;
	WORD sp;

public:
	TotsRunner();

	void loadProgram(vector<uchar>);
	void print();
	void execute();
};