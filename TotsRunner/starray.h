#pragma once

#include "defs.h"

template <typename T>
class starray
{
public:
	unsigned long size;
	T * values;

	starray()
	{
		this->size = 0;
		this->values = nullptr;
	}
	starray(unsigned long size)
	{
		this->size = size;
		if (size != 0)
			this->values = new T[size]();
	}
	~starray();

	void release();

};

template <typename T>
starray<T>::~starray()
{
	release();
}

template<typename T>
void starray<T>::release()
{
	delete[] values;
	values = nullptr;
}