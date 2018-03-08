#include "ValueObject.h"

ValueObject::ValueObject()
{
	this->type = kNONE;
}

ValueObject::ValueObject(Type type, WORD v0)
{
	this->type = type;
	this->v0 = v0;
	this->v1 = 0;
}

ValueObject::ValueObject(Type type, WORD v0, WORD v1)
{
	this->type = type;
	this->v0 = v0;
	this->v1 = v1;
}

ValueObject * ValueObject::ToInt()
{
	switch (this->type)
	{
	case Type::kINT:
	{
		return this;
	}
	case Type::kFLOAT:
	{
		Float val = *(Float*)&this->v0;
		this->v0 = (WORD)val;
		this->type = Type::kINT;
		return this;
	}
	}
	return nullptr;
}

ValueObject * ValueObject::ToFloat()
{
	switch (this->type)
	{
	case Type::kINT:
	{
		Float val = (Float)this->v0;
		this->v0 = *(WORD*)&val;
		this->type = Type::kFLOAT;
	}
	case Type::kFLOAT:
	{		
		return this;
	}
	}
	return nullptr;
}

WORD ValueObject::AsInt()
{
	return this->v0;
}

Float ValueObject::AsFloat()
{
	return *(Float*)&this->v0;
}

const char * ValueObject::TypeToCharArray(Type type)
{
	switch (type)
	{
	case Type::kINT:
		return "Int";
		break;
	case Type::kFLOAT:
		return "Float";
		break;
	case kOBJECTREF:
		return "ObjectRef";
		break;
	default:
		return "Unk";
	}
}

ostream & operator<<(ostream & os, const ValueObject & dt)
{
	os << ValueObject::TypeToCharArray(dt.type) << " ";
	switch (dt.type) {
	case Type::kINT:
	{
		os << dt.v0;
		break;
	}
	case Type::kFLOAT:
	{
		os << *(Float*)&dt.v0;
		break;
	}
	case Type::kOBJECTREF:
		os << hex << dt.v0;
		break;
	}
	return os;
}
