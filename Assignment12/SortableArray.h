#pragma once
//Programmer     : Pratistha Maharjan
//Programmer's ID: 1650717
#ifndef SortableArray_h
#define SortableArray_h

template <typename T>
class SortableArray
{
	T* values;
	int cap;
	T dummy;

public:
	SortableArray(int = 2);
	SortableArray(const SortableArray<T>&);
	~SortableArray() { delete[] values; };
	SortableArray<T>& operator = (const SortableArray<T>&);
	int capacity() const { return cap; }
	void capacity(int);
	const T& operator[] (int) const;
	T& operator[] (int);
	void sort(int);
};

template<typename T>
SortableArray<T>::SortableArray(int cap)
{
	this->cap = cap;
	values = new T[cap];
	dummy = T();
	for (int i = 0; i < cap; i++)
		values[i] = T();
}

template<typename T>
SortableArray<T>::SortableArray(const SortableArray<T>& original)
{
	cap = original.cap;
	values = new T[cap];
	for (int i = 0; i < cap; i++)
		values[i] = original.values[i];
	dummy = original.dummy;
}


template<typename T>
SortableArray<T>& SortableArray<T>::operator = (const SortableArray<T>& original)
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
void SortableArray<T>::capacity(int cap)
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
const T& SortableArray<T>::operator[](int index) const
{
	if (index < 0 || index >= cap) return T();
	return values[index];
}

template<typename T>
T& SortableArray<T>::operator[](int index)
{
	if (index < 0) return dummy;
	if (index >= cap) capacity(2 * index);
	return values[index];
}

template<typename T>
void SortableArray<T>::sort(int index)
{
	for (int i = 0; i < index; i++)
	{
		for (int j = i + 1; j < index; j++)
		{
			if (values[i] > values[j])
			{
				const T temp = values[i];
				values[i] = values[j];
				values[j] = temp;
			}
		}
	}
}


#endif
