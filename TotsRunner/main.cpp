//#include "VirtualThreadWorker.h"
//#include "MethodDefBuilder.h"
//#include "MethodDefTableBuilder.h"
//#include "ExecutionRegistry.h"
//
//// TODO: How to exception handling asm? 
//
//int main()
//{
//	DLOG("Running in Verbose...");
//	MethodDefTableBuilder defbldr;		
//
//	MethodDefBuilder bldr;
//	MethodDefBuilder bldr2;
//	starray<UChar> * code = bldr.Lvarg0().Dup().Lvindi32().Dup().Muli32().Stindi32().Ret().build();
//	MethodDef * def = new MethodDef(code, 8, 2, 1, false);	
//
//	defbldr.add(def);
//
//	code = bldr2.Lvi8(37).Stloc0().Lvaloci16(0).Call(0x00000000).Lvloc0().Pop().Ret().build();
//	def = new MethodDef(code, 8, 2, 0, false);
//
//	defbldr.add(def);
//	ExecutionRegistry * er = ExecutionRegistry::create(defbldr.build());	
//	
//	VirtualThreadWorker vtw = VirtualThreadWorker();
//
//	starray<DWRD> * args = new starray<DWRD>(0);
//	vtw.start(def->call(args));
//
//	delete er;
//
//	system("pause");
//	return 0;
//}

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <string>

#include <TotsParserDriver.h>
#include <SyntaxRoot.h>
#include <TotsAotCompiler.h>

using Driver = Tots::Language::Syntax::Parser::TotsParserDriver;
using Compiler = Tots::Language::Compiler::TotsAotCompiler;
using namespace std;

int main()
{
	Driver driver;
	istringstream ss;
	string a = "int main() { int x = 5; int y = 13; }";
	ss.str(a);
	driver.parse(ss);

	Compiler compiler;

	SyntaxRoot * root = driver.root;

	cout << (*root->functions)[0]->returnType->identifier << " " << (*root->functions)[0]->identifier << endl;
	compiler.compileFunction((*root->functions)[0]->statements);

	system("pause");
	return(EXIT_SUCCESS);
}
