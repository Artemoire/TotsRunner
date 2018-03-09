//#include "TotsRunner.h"
//#include <iostream>
//#include "CharCodes.h"
//#include "Arith.h"
//
//TotsRunner::TotsRunner()
//{
//	sp = -1;
//	pc = 0;
//	stack = vector<ValueObject>(1000);
//}
//
//void TotsRunner::loadProgram(vector<UChar> charCodeArray)
//{
//	TotsRunner::charCodeArray = charCodeArray;
//}
//
//void TotsRunner::print()
//{
//	cout << "TOS " << stack[sp] << endl;
//}
//
//void TotsRunner::execute()
//{
//	while (pc < charCodeArray.size())
//	{
//		CharCodes code = static_cast<CharCodes>(charCodeArray[pc]);
//		switch (code)
//		{
//		case CharCodes::kLVI_1:
//		{
//			stack[++sp] = ValueObject(Type::kINT, -1);
//			break;
//		}
//		case CharCodes::kLVI0:
//		{
//			stack[++sp] = ValueObject(Type::kINT, 0);
//			break;
//		}
//		case CharCodes::kLVI8:
//		{
//			DWRD val = charCodeArray[++pc];
//			stack[++sp] = ValueObject(Type::kINT, val);
//			break;
//		}
//		case CharCodes::kLVI16:
//		{
//			DWRD val = (charCodeArray[++pc]) | (charCodeArray[++pc] << 8);
//			stack[++sp] = ValueObject(Type::kINT, val);
//			break;
//		}
//		case CharCodes::kLVI32:
//		{
//			DWRD val = (charCodeArray[++pc]) | (charCodeArray[++pc] << 8) | (charCodeArray[++pc] << 16) | (charCodeArray[++pc] << 24);
//			stack[++sp] = ValueObject(Type::kINT, val);
//			break;
//		}
//		case CharCodes::kLVF:
//		{
//			DWRD val = (charCodeArray[++pc]) | (charCodeArray[++pc] << 8) | (charCodeArray[++pc] << 16) | (charCodeArray[++pc] << 24);
//			stack[++sp] = ValueObject(Type::kFLOAT, val);
//			break;
//		}
//		case CharCodes::kADD:
//		{
//#ifdef _DEBUG
//			cout << "+=" << endl;
//#endif // _DEBUG
//			Arith::Add(&stack[--sp], &stack[sp + 1]);
//			break;
//		}
//		case CharCodes::kSUB:
//		{
//#ifdef _DEBUG
//			cout << "-=" << endl;
//#endif // _DEBUG
//			Arith::Sub(&stack[--sp], &stack[sp + 1]);
//			break;
//		}
//		case CharCodes::kMUL:
//		{
//#ifdef _DEBUG
//			cout << "*=" << endl;
//#endif // _DEBUG
//			Arith::Mul(&stack[--sp], &stack[sp + 1]);
//			break;
//		}
//		case CharCodes::kDIV:
//		{
//#ifdef _DEBUG
//			cout << "/=" << endl;
//#endif // _DEBUG
//			Arith::Div(&stack[--sp], &stack[sp + 1]);
//			break;
//		}
//		default:
//			break;
//		}
//		print();
//		pc++;
//	};
//}