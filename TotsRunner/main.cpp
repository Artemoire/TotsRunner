#include "TotsRunner.h"
#include "MethodDefBuilder.h"

#include <cstdio>


int main()
{
	DLOG("Running in Verbose...");
	MethodDefBuilder builder;
	vector<UChar> code = builder.LVI8(2).LVI8(2).add().LVI8(3).mul().LVF(0.333F).div().build();
	TotsRunner t;

	t.loadProgram(code);
	t.execute();  

	/*auto v = ValueObject(Type::kPOINTER, 1025, 1024 + 256 + 512);
	unsigned long long i = 0x0000070000000401;
	unsigned __int64 x = *(unsigned __int64 *)(((Word)&v + sizeof(Type)));*/

	system("pause");
	return 0;
}