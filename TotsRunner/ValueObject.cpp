#include "ValueObject.h"

ValueObject::ValueObject()
{
	this->type = kOBJECTREF;
	this->value = (WORD)0;
}

ValueObject::ValueObject(Type type, WORD value)
{
	this->type = type;
	this->value = value;
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
		FLOAT val = *(FLOAT*)&this->value;
		this->value = (WORD)val;
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
		FLOAT val = (FLOAT)this->value;
		this->value = *(WORD*)&val;
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
	return this->value;
}

FLOAT ValueObject::AsFloat()
{
	return *(FLOAT*)&this->value;
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
		os << dt.value;
		break;
	}
	case Type::kFLOAT:
	{
		os << *(FLOAT*)&dt.value;
		break;
	}
	case Type::kOBJECTREF:
		os << hex << dt.value;
		break;
	}
	return os;
}
