#pragma once

#include "defs.h"

enum Type : UChar
{
	kINT = 0,
	kFLOAT,
	kPOINTER,
	//ARRAY,
	kOBJECTREF,
	kNONE
};

class ValueObject
{
public:
	Type type;
	WORD v0;
	WORD v1;

	ValueObject();	
	ValueObject(Type, WORD);
	ValueObject(Type, WORD, WORD);

	ValueObject * ToInt();
	ValueObject * ToFloat();
	WORD AsInt();
	Float AsFloat();

	static const char * TypeToCharArray(Type);
	friend ostream& operator<<(ostream& os, const ValueObject& dt);
};