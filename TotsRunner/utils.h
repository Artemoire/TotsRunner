#pragma once

#include <iostream>

using namespace std;

void tprintf(const char* format);

template<typename T, typename... Targs>
void tprintf(T value, Targs... Fargs);

template<typename T, typename ...Targs>
void tprintf(T value, Targs ...Fargs)
{
	cout << value << endl;
	tprintf(Fargs...);
}