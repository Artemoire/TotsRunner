#include "FunctionDef.h"

FunctionDef::FunctionDef(char * id, TypeDef * t, starray<TypeDef*> a, starray<TypeDef*> l, starray<UChar> b) : Def(id)
{
	returnType = t;
	args = a;
	locals = l;
	body = b;
}
