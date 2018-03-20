#pragma once

#include "TypeDef.h"
#include "starray.h"

class FunctionDef : public Def
{
public:
	TypeDef * returnType;

	starray<TypeDef*> args;
	starray<TypeDef*> locals;
	starray<UChar> body;	

	FunctionDef(char *, TypeDef *, starray<TypeDef*>, starray<TypeDef*>, starray<UChar>);
}; 