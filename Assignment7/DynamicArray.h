#pragma once
#ifndef DynamicArray_h
#define DynamicArray_h

#include <algorithm>
using namespace std;

template <typename V>
class DynamicArray
{
	V* values;
	int cap;
	V dummy;

public:
	DynamicArray(int = 2); //constructor //default = 2
	DynamicArray(const DynamicArray<V>&); //copy constructor
	~DynamicArray() { delete[] values; }  //default 

	DynamicArray<V>& operator = (const DynamicArray<V>&); //assignemtn operator 

	int capacity() const { return cap; }
	void capacity(int);  //setter 
	const V&  operator [ ] (int) const; //getter 
	V& operator[ ] (int); //setter
};

template <typename V> //constructor
DynamicArray<V>::DynamicArray(int cap)
{
	this->cap = cap;
	values = new V[cap];

	for (int i = 0; i < cap; i++)
	{
		values[i] = V();
	}
}

template <typename V> //assignment operator
DynamicArray<V>& DynamicArray<V>::operator=(const DynamicArray<V>& original)
{
	if (this != &original) // of it's not a self copy...
	{
		// do what the destructor does
		delete[] values;

		// do what the copy constructor does
		cap = original.cap; // still just a copy
		values = new V[cap]; // not a copy -- new object gets its own array
		for (int i = 0; i < cap; i++) // copy the contents of the array from the original...
			values[i] = original.values[i]; // ...to the copy
		dummy = original.dummy; // not really necessary because who cares what dummy contains?
	}

	return *this; // return a self reference
}

template <typename V> //setter
void DynamicArray<V>::capacity(int cap)
{
	// allocate a new array with the new capacity
	V* temp = new V[cap];

	// get the lesser of the new and old capacities
	int limit = min(cap, this->cap); // requires the C++ "algorithm" library
	// Or use the conditional operator with include the "algorithm" library
	//int limit = (cap < this->cap ? cap : this->cap);

	// copy the contents
	for (int i = 0; i < limit; i++)
		temp[i] = values[i];

	// set added values to their defaults
	for (int i = limit; i < cap; i++)
		temp[i] = V();

	// deallocate original array
	delete[] values;

	// switch newly allocated array into the object 
	values = temp;

	//update the capacity
	this->cap = cap;
}

template <typename V> //copy constructor
DynamicArray<V>::DynamicArray(const DynamicArray<V>& original)
{
	cap = original.cap; // still just a copy
	values = new V[cap]; // not a copy -- new object gets its own array

	for (int i = 0; i < cap; i++) // copy the contents of the array from the original...
		values[i] = original.values[i]; // ...to the copy
	dummy = original.dummy; // not really necessary because who cares what dummy contains?
}

template <typename V>
 const V& DynamicArray<V>:: operator[ ] (int index) const // getter
{
	 if (index < 0 || index >= cap) return V();
	return values[index];
}

template <typename V>
V& DynamicArray<V>::operator[ ] (int index) // setter
{
	
		if (index < 0) {
			return dummy; // a copy
		}
		else if (index >= cap) {
			capacity(2 * index);
		}
		return values[index]; // a copy	
}


#endif
