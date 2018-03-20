#include "starray.h"

template<typename T>
starray<T>::starray()
{
	this->size = 0;
	this->values = nullptr;
}

template<typename T>
starray<T>::starray(unsigned long size)
{
	this->size = size;
	if (size != 0)
		this->values = new T[size]();
}

template<typename T>
void starray<T>::release()
{
	delete[] values;
	values = nullptr;
}