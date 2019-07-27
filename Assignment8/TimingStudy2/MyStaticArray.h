//Programmer     : Pratistha Maharjan
//Programmer's ID: 1650717
#ifndef MyStaticArray_h
#define MyStaticArray_h

template <typename T, int CAP>
class StaticArray
{
	T values[CAP];
	T dummy;

public:
	StaticArray();
	int capacity() const { return CAP; }
	const T& operator[] (int) const;
	T& operator[] (int);
};

template<typename T, int CAP>
StaticArray<T, CAP>::StaticArray()
{
	dummy = T();
	for (int i = 0; i < CAP; i++)
		values[i] = T();
}

template<typename T, int CAP>
T& StaticArray<T, CAP>::operator[](int index)
{
	if (index < 0) return dummy;
	if (index >= CAP) return dummy;
	return values[index];
}

template<typename T, int CAP>
const T& StaticArray<T, CAP>::operator[](int index) const
{
	if (index < 0 || index >= CAP) return T();
	return values[index];
}

#endif
