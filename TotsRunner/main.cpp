#include <iostream>
#include "TotsRunner.h"
#include "CharCodeBuilder.h"

int main()
{
	CharCodeBuilder builder;
	vector<uchar> code = builder.ldi8(2).ldi8(2).add().ldi8(3).mul().ldi8(6).div().build();
	TotsRunner t;

	t.loadProgram(code);
	t.execute();  

	system("pause");
	return 0;
}