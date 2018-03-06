#include "Arith.h"

#include <iostream>

using namespace std;

WORD max(WORD v1, WORD v2)
{
	return (v1 > v2) ? v1 : v2;
}

void Arith::Add(ValueObject * v1, ValueObject * v2)
{
	switch ((Type)max(v1->type, v2->type))
	{
	case Type::kINT: // both are ints
	{
		v1->value += v2->value;
		return;
	}
	case Type::kFLOAT:
	{
		if (v1->type != Type::kFLOAT)
		{
			FLOAT val = v1->ToFloat()->AsFloat() + v2->AsFloat();
			v1->value = *(WORD*)&val;
			return;
		}
		else
		{
			FLOAT val = v1->AsFloat() + v2->ToFloat()->AsFloat();
			v1->value = *(WORD*)&val;
			return;
		}
	}
	}

#ifdef _DEBUG
	cout << "Illegal Operation" << endl;
#endif // _DEBUG	
}

void Arith::Sub(ValueObject * v1, ValueObject * v2)
{
	switch ((Type)max(v1->type, v2->type))
	{
	case Type::kINT: // both are ints
	{
		v1->value -= v2->value;
		return;
	}
	case Type::kFLOAT:
	{
		if (v1->type != Type::kFLOAT)
		{
			FLOAT val = v1->ToFloat()->AsFloat() - v2->AsFloat();
			v1->value = *(WORD*)&val;
			return;
		}
		else
		{
			FLOAT val = v1->AsFloat() - v2->ToFloat()->AsFloat();
			v1->value = *(WORD*)&val;
			return;
		}
	}
	}

#ifdef _DEBUG
	cout << "Illegal Operation" << endl;
#endif // _DEBUG	
}

void Arith::Div(ValueObject * v1, ValueObject * v2)
{
	switch ((Type)max(v1->type, v2->type))
	{
	case Type::kINT: // both are ints
	{
		WORD v2val = v2->value;
		if (v2val == 0)
		{
#ifdef _DEBUG
			cout << "Division by zero. Oops" << endl;
#endif // _DEBUG	
			system("pause"); // TODO: Throw Exception
			exit(1);
		}

		v1->value /= v2val;
		return;
	}
	case Type::kFLOAT:
	{
		if (v1->type != Type::kFLOAT)
		{
			FLOAT v2val = v2->AsFloat();

			if (v2val == 0.0F)
			{
#ifdef _DEBUG
				cout << "Division by zero. Oops" << endl;
#endif // _DEBUG	
				//return;
			}

			FLOAT val = v1->ToFloat()->AsFloat() / v2val;
			v1->value = *(WORD*)&val;
			return;
		}
		else
		{
			FLOAT v2val = v2->ToFloat()->AsFloat();

			if (v2val == 0.0F)
			{
#ifdef _DEBUG
				cout << "Division by zero. Oops" << endl;
#endif // _DEBUG	
				//return;
			}

			FLOAT val = v1->AsFloat() / v2val;
			v1->value = *(WORD*)&val;
			return;
		}
	}
	}

#ifdef _DEBUG
	cout << "Illegal Operation" << endl;
#endif // _DEBUG	
}

void Arith::Mul(ValueObject * v1, ValueObject * v2)
{
	switch ((Type)max(v1->type, v2->type))
	{
	case Type::kINT: // both are ints
	{
		v1->value *= v2->value;
		return;
	}
	case Type::kFLOAT:
	{
		if (v1->type != Type::kFLOAT)
		{
			FLOAT val = v1->ToFloat()->AsFloat() * v2->AsFloat();
			v1->value = *(WORD*)&val;
			return;
		}
		else
		{
			FLOAT val = v1->AsFloat() * v2->ToFloat()->AsFloat();
			v1->value = *(WORD*)&val;
			return;
		}
	}
	}

#ifdef _DEBUG
	cout << "Illegal Operation" << endl;
#endif // _DEBUG	
}