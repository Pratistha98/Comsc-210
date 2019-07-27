//Programmer     : Pratistha Maharjan
//Programmer's ID: 1650717
#ifndef MyDynamicArray_h
#define MyDynamicArray_h

template <typename T>
class DynamicArray
{
	T* values;
	int cap;
	T dummy;

public:
	DynamicArray(int = 2);
	DynamicArray(const DynamicArray<T>&);
	~DynamicArray() { delete[] values; };
	DynamicArray<T>& operator = (const DynamicArray<T>&);
	int capacity() const { return cap; }
	void capacity(int);
	const T& operator[] (int) const;
	T& operator[] (int);
};

template<typename T>
DynamicArray<T>::DynamicArray(int cap)
{
	this->cap = cap;
	values = new T[cap];
	dummy = T();
	for (int i = 0; i < cap; i++)
		values[i] = T();
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& original)
{
	cap = original.cap;
	values = new T[cap];
	for (int i = 0; i < cap; i++)
		values[i] = original.values[i];
	dummy = original.dummy;
}


template<typename T>
DynamicArray<T>& DynamicArray<T>::operator = (const DynamicArray<T>& original)
{
	if (this != &original)
	{
		delete[] values;
		cap = original.cap;
		values = new T[cap];
		for (int i = 0; i < cap; i++)
			values[i] = original.values[i];
		dummy = original.dummy;
	}
	return *this;
}

template<typename T>
void DynamicArray<T>::capacity(int cap)
{
	T* temp = new T[cap];
	int limit; //= min(cap, this->cap);
	if (cap < this->cap)
		limit = cap;
	else
		limit = this->cap;
	for (int i = 0; i < limit; i++)
		temp[i] = values[i];
	for (int i = limit; i < cap; i++)
		temp[i] = T();
	delete[] values;
	values = temp;
	this->cap = cap;
}

template<typename T>
const T& DynamicArray<T>::operator[](int index) const
{
	if (index < 0 || index >= cap) return T();
	return values[index];
}

template<typename T>
T& DynamicArray<T>::operator[](int index)
{
	if (index < 0) return dummy;
	if (index >= cap) capacity(2 * index);
	return values[index];
}

#endif
