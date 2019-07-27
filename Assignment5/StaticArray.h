#pragma once

#ifndef MyStaticArray_h
#define MyStaticArray_h

template <typename V, int CAP>
class StaticArray
{
	V values[CAP];
	V dummy;

public:
	StaticArray();
	int capacity() const { return 100; }
	const V& operator [] (int) const;
	V& operator[] (int);
};


template<typename V, int CAP>
StaticArray <V, CAP > ::StaticArray()
{
	dummy = V();
	for (int index = 0; index < CAP; index++)
		values[index] = V();
}

template<typename V, int CAP>
const V& StaticArray <V, CAP > ::operator[] (int index) const
{
	if (index < 0 || index >= CAP)
		return dummy;
	return values[index];
}

template<typename V, int CAP>
V& StaticArray <V, CAP > ::operator[](int index)
{
	if (index < 0 || index >= CAP)
		return dummy;
	return values[index];
}


#endif 