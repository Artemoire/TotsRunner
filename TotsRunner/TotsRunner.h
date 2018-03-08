#pragma once

#include <vector>
#include "defs.h"
#include "ValueObject.h"

using namespace std;

class TotsRunner {

	vector<UChar> charCodeArray;
	vector<ValueObject> stack;
	WORD pc;
	WORD sp;

public:
	TotsRunner();

	void loadProgram(vector<UChar>);
	void print();
	void execute();
};