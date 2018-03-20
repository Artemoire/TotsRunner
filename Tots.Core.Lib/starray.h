#pragma once

template <typename T>
class starray
{
public:
	unsigned long size;
	T * values;

	starray();
	starray(unsigned long size);

	void release();

};

