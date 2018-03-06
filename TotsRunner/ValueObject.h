#pragma once

#include "defs.h"
#include <iostream>

using namespace std;

enum Type
{
	//NULL = 0,
	kINT = 0,
	kFLOAT,
	//ARRAY,
	kOBJECTREF
};

class ValueObject
{
public:
	Type type;
	WORD value;

	ValueObject();
	ValueObject(Type, WORD);

	ValueObject * ToInt();
	ValueObject * ToFloat();
	WORD AsInt();
	FLOAT AsFloat();

	static const char * TypeToCharArray(Type);
	friend ostream& operator<<(ostream& os, const ValueObject& dt);
};