#pragma once

#include <iostream>

using namespace std;

#define EMPTY_OP(X) do{} while(0)

void tprintf(const char* format);

template<typename T, typename... Targs>
void tprintf(T value, Targs... Fargs);

#define ERR(...) tprintf(__VA_ARGS__); exit(1)

#ifdef _VERBOSE
#define DLOG(X) cout << X << endl
#define ERR(...) tprintf(__VA_ARGS__); system("pause"); exit(1)
#else
#define DLOG(X) EMPTY_OP(X)
#endif // _VERBOSE

typedef unsigned char UChar;
typedef unsigned long WORD;
typedef float Float;

template<typename T, typename ...Targs>
void tprintf(T value, Targs ...Fargs)
{
	cout << value << endl;
	tprintf(Fargs...);
}