#include "TotsRunner.h"
#include <iostream>
#include "CharCodes.h"

TotsRunner::TotsRunner()
{
	sp = -1;
	pc = 0;
	stack = vector<WORD>(1000);
}

void TotsRunner::loadProgram(vector<uchar> charCodeArray)
{
	TotsRunner::charCodeArray = charCodeArray;
}

void TotsRunner::print()
{
	cout << "TOS " << stack[sp] << endl;
}

void TotsRunner::execute()
{
	while (pc < charCodeArray.size())
	{
		CharCodes code = static_cast<CharCodes>(charCodeArray[pc]);
		switch (code)
		{
		case CharCodes::LdNeg:
		{
			stack[++sp] = -1;
			break;
		}
		case CharCodes::Ld0:
		{
			stack[++sp] = 0;
			break;
		}
		case CharCodes::LdI8:
		{
			WORD val = charCodeArray[++pc];
			stack[++sp] = val;
			break;
		}
		case CharCodes::LdI16:
		{
			WORD val = (charCodeArray[++pc]) | (charCodeArray[++pc] << 8);
			stack[++sp] = val;
			break;
		}
		case CharCodes::LdI32:
		{
			WORD val = (charCodeArray[++pc]) | (charCodeArray[++pc] << 8) | (charCodeArray[++pc] << 16) | (charCodeArray[++pc] << 24);
			stack[++sp] = val;
			break;
		}
		case CharCodes::Add:
		{
#ifdef _DEBUG
			cout << "+=" << endl;
#endif // _DEBUG
			stack[--sp] = stack[sp] + stack[sp + 1];
			break;
		}
		case CharCodes::Sub:
		{
#ifdef _DEBUG
			cout << "-=" << endl;
#endif // _DEBUG
			stack[--sp] = stack[sp] - stack[sp + 1];
			break;
		}
		case CharCodes::Mul:
		{
#ifdef _DEBUG
			cout << "*=" << endl;
#endif // _DEBUG
			stack[--sp] = stack[sp] * stack[sp + 1];
			break;
		}
		case CharCodes::Div:
		{
#ifdef _DEBUG
			cout << "/=" << endl;
#endif // _DEBUG
			stack[--sp] = stack[sp] / stack[sp + 1];
			break;
		}
		default:
			break;
		}
		print();
		pc++;
	};
}