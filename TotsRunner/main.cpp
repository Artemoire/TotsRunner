#include "TotsRunner.h"
#include "VirtualThreadWorker.h"
#include "MethodDef.h"
#include "MethodDefBuilder.h"

// TODO: How to exception handling asm? 

int main()
{
	DLOG("Running in Verbose...");
	MethodDefBuilder bldr;
	starray<UChar> * code = bldr.Lvi8(255).Stloc0().Lvloc0().Add(23UL).Stloc1().Lvloc1().Add(1UL).build();
	starray<DWRD> * args = new starray<DWRD>(0);
	MethodDef def = MethodDef(code, 8, 2, 0);
	VirtualThreadWorker vtw = VirtualThreadWorker();
	vtw.start(def.call(args));

	/*MethodDefBuilder builder;
	vector<UChar> code = builder.LVI8(2).LVI8(2).add().LVI8(3).mul().LVF(0.333F).div().build();
	TotsRunner t;

	t.loadProgram(code);
	t.execute();  */

	/*auto v = ValueObject(Type::kPOINTER, 1025, 1024 + 256 + 512);
	unsigned long long i = 0x0000070000000401;
	unsigned __int64 x = *(unsigned __int64 *)(((Word)&v + sizeof(Type)));*/
	
	/*starray<UInt64> s = starray<UInt64>(11);
	UInt8 i = 128;
	s.values[0] = i;
	cout << (long)((Int8)s.values[0]) << endl;*/
	/*cout << (UInt32)s.values[0] << endl;
	cout << ((Int8)s.values[0]) << endl;*/

	system("pause");
	return 0;
}