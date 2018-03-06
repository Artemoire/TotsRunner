#include <iostream>
#include "TotsRunner.h"
#include "MethodBuilder.h"

int main()
{
	MethodBuilder builder;
	vector<UCHAR> code = builder.LVI8(2).LVI8(2).add().LVI8(3).mul().LVF(0.333F).div().build();
	TotsRunner t;

	t.loadProgram(code);
	t.execute();  

	system("pause");
	return 0;
}