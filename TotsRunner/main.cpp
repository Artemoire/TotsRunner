#include <iostream>
#include "TotsRunner.h"
#include "MethodBuilder.h"

int main()
{
	MethodBuilder builder;
	vector<uchar> code = builder.ldi8(2).ldi8(2).add().ldi8(3).mul().ldi8(6).div().build();
	TotsRunner t;

	cout << &t << endl;

	WORD * h = (WORD*)&t;
	t = *(TotsRunner*)h;

	cout << &t << endl;

	t.loadProgram(code);
	t.execute();  

	system("pause");
	return 0;
}