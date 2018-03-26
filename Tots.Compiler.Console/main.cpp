#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <string>

#include <TotsParserDriver.h>
#include <SyntaxRoot.h>
#include <TotsAotCompiler.h>

using Driver = Tots::Language::Syntax::Parser::TotsParserDriver;
//using Compiler = Tots::Language::Compiler::TotsAotCompiler;
using namespace std;

int main()
{
	Driver driver;
	istringstream ss;
	string a = "int main() { int x = 5; var y = 6; 1+x+3+4*6; }";
	//string a = "int main() { int x; int y; int z; int w; x = y = w = z = 42; }";
	ss.str(a);
	driver.parse(ss);

	//Compiler compiler;

	//SyntaxRoot * root = driver.root;

	//cout << (*root->functions)[0]->returnType->identifier << " " << (*root->functions)[0]->identifier << endl;
	//compiler.compileFunction((*root->functions)[0]->statements);	

	system("pause");
	return(EXIT_SUCCESS);
}
