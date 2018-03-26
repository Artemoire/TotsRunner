#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <string>

#include <TotsParserDriver.h>
#include <SyntaxRoot.h>
#include <TotsAotCompiler.h>

#include <DeclarationBuilder.h>

using Driver = Tots::Language::Syntax::Parser::TotsParserDriver;
//using Compiler = Tots::Language::Compiler::TotsAotCompiler;
using namespace std;

int main()
{
	Driver driver;
	istringstream ss;
	string a = "namespace A.X.B { class Program { public static int x; public static void Main() {} static class Builder {} } }";
	ss.str(a);
	driver.parse(ss);

	//Compiler compiler;

	SyntaxRoot * root = driver.root;
	
	DeclarationBuilder db;

	db.parse_root(root);

	//cout << (*root->functions)[0]->returnType->identifier << " " << (*root->functions)[0]->identifier << endl;
	//compiler.compileFunction((*root->functions)[0]->statements);	

	system("pause");
	return(EXIT_SUCCESS);
}
