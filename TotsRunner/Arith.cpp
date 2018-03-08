#include "Arith.h"

#define AS_F32(X) *(Float*)&X
#define AS_I32(X) *(WORD*)&X

#define ERR_ABORT(...) ERR(__VA_ARGS__, "Aborting...")

// TODO: TEMPORARY
#define ERR_TODO_PTR() ERR_ABORT("TODO: PTRS")

#define ERR_ADD() ERR_ABORT("Illegal Add")
#define ERR_SUB() ERR_ABORT("Illegal Sub")
#define ERR_MUL() ERR_ABORT("Illegal Mul")
#define ERR_DIV() ERR_ABORT("Illegal Div")

#define ERR_DIV_ZERO() ERR_ABORT("Division By Zero. Oops")

WORD max(WORD v1, WORD v2)
{
	return (v1 > v2) ? v1 : v2;
}

void Arith::Add(ValueObject * v1, ValueObject * v2)
{
	if (v1->type != Type::kPOINTER && v1->type != v2->type)
	{
		ERR_ADD();
	}

	switch (v1->type)
	{
		case Type::kINT: // both are ints
		{
			v1->v0 += v2->v0;
			return;
		}
		case Type::kFLOAT:
		{
			Float val = AS_F32(v1->v0) + AS_F32(v1->v0);		
			v1->v0 = AS_I32(val);
			return;
		}
		case Type::kPOINTER:
		{
			ERR_TODO_PTR();
		}
	}

	ERR_ADD();
}

void Arith::Sub(ValueObject * v1, ValueObject * v2)
{
	if (v1->type != Type::kPOINTER && v1->type != v2->type)
	{
		ERR_SUB();
	}

	switch (v1->type)
	{
		case Type::kINT: // both are ints
		{
			v1->v0 -= v2->v0;
			return;
		}
		case Type::kFLOAT:
		{
			Float val = AS_F32(v1->v0) - AS_F32(v1->v0);
			v1->v0 = AS_I32(val);
			return;
		}
		case Type::kPOINTER:
		{
			ERR_TODO_PTR();
		}
	}

	ERR_SUB();
}

void Arith::Mul(ValueObject * v1, ValueObject * v2)
{
	if (v1->type != v2->type)
	{
		ERR_MUL();
	}

	switch (v1->type)
	{
		case Type::kINT: // both are ints
		{
			v1->v0 *= v2->v0;
			return;
		}
		case Type::kFLOAT:
		{
			Float val = AS_F32(v1->v0) * AS_F32(v1->v0);
			v1->v0 = AS_I32(val);
			return;
		}
	}

	ERR_MUL();
}

void Arith::Div(ValueObject * v1, ValueObject * v2)
{
	if (v1->type != v2->type)
	{
		ERR_DIV();
	}

	switch (v1->type)
	{
		case Type::kINT: // both are ints
		{
			if (v2->v0 == 0)
			{
				ERR_DIV_ZERO();
			}
			v1->v0 /= v2->v0;
			return;
		}
		case Type::kFLOAT:
		{
			if (AS_F32(v2->v0) == 0.0F)
			{
				ERR_DIV_ZERO();
			}
			Float val = AS_F32(v1->v0) / AS_F32(v1->v0);
			v1->v0 = AS_I32(val);
			return;
		}
	}

	ERR_DIV();
}