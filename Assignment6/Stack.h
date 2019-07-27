//Programmar     : Pratistha Maharjan
//Programmar's ID: 1650717


#pragma once
#ifndef Stack_h
#define Stack_h

#include <algorithm>
template <typename V>
class Stack
{
	V* values;
	V dummy;
	int cap;
	int siz; //trace the size
	void capacity(int);
public:
	 
	Stack(int = 2); 
	Stack(const Stack<V>&); //copy constructor 
	~Stack() { delete[] values; }
	Stack<V>& operator= (const Stack<V>&);
	void push(const V&);
	V&  peek();
	void pop(); 
	int size() const; 
	bool empty() const;
	void clear();
};

template <typename V>
void Stack<V> ::capacity(int cap)
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


template <typename V>
Stack<V> ::Stack(const Stack<V> &original)
{
	cap = original.cap; // still just a copy
	values = new V[cap]; // not a copy -- new object gets its own array

	for (int i = 0; i < cap; i++) // copy the contents of the array from the original...
		values[i] = original.values[i]; // ...to the copy
	dummy = original.dummy; // not really necessary because who cares what dummy contains?
	siz = original.siz;
}
template <typename V>
Stack<V> ::Stack(int cap)
{
	this->cap = cap;
	values = new V[cap];

	for (int i = 0; i < cap; i++)
	{
		values[i] = V();
	}
	dummy = V(); 
	siz = 0;
}
template <typename V>
Stack<V>& Stack<V> ::operator=(const Stack<V>& orig)
{
	if (this != &orig)
	{
		delete[] values;
		cap = orig.cap;
		siz = orig.siz;
		dummy = orig.dummy;
		values = new V[cap];
		for (int i = 0; i < siz; i++)
			values[i] = orig.values[i];
	}
	return *this;
}
template<typename V>
void Stack<V>::push(const V& value)
{
	if (siz == cap - 1) capacity(2 * cap);
	values[siz] = value;
	++siz;
}

template<typename V>
V& Stack<V>::peek() 
{
	if (siz > 0)
		return values[siz - 1];
	return values[0];
}

template<typename V>
void Stack<V>::pop()
{
	if (siz > 0) 
		--siz;
}

template<typename V>
void Stack<V>::clear()
{
	siz = 0;
}

template<typename V>
int Stack<V>::size() const
{
	return siz;
}

template<typename V>
bool Stack<V>::empty() const
{
	return (siz == 0 ? true : false);
}
#endif


