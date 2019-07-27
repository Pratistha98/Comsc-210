//Programmar: Pratistha Maharjan
//Programmar's ID: 1650717

#pragma once
#ifndef PriorityQueue_h
#define PriorityQueue_h
#include <iostream>

template<typename V>
class PriorityQueue
{
	V* values;
	int cap;
	int siz;
	void capacity(int);

public:
	PriorityQueue(int = 2);
	PriorityQueue(const PriorityQueue<V>&);
	~PriorityQueue() { delete[] values; }
	PriorityQueue<V>& operator = (const PriorityQueue<V>&);

	void push(const V&);
	void pop();
	V top() const { return values[0]; }
	int size() { return siz; }
	bool empty() { return siz == 0 ? true : false; }
	void clear() { siz = 0; }
};

//main constructor
template<typename V>
PriorityQueue<V>::PriorityQueue(int capacity)
{
	cap = capacity;
	siz = 0;
	values = new V[cap];
}

//copy constructor
template <typename V>
PriorityQueue<V>::PriorityQueue(const PriorityQueue<V>& original)
{
	cap = original.cap;
	values = new V[cap];
	for (int i = 0; i < cap; i++)
		values[i] = original.values[i];
	siz = original.siz;
}

//assignment operator
template <typename V>
PriorityQueue<V>& PriorityQueue<V>::operator=(const PriorityQueue<V>& original)
{
	if (this != &original)
	{
		delete[] values;

		cap = original.cap;
		values = new V[cap];
		for (int i = 0; i < cap; i++)
			values[i] = original.values[i];
		siz = original.siz;
	}
	return *this; // return a self reference
}

//push
template<typename V>
void PriorityQueue<V>::push(const V& value)
{
	if (siz == cap)
		capacity(cap * 2);

	values[siz] = value;

	int index = siz;

	while (index != 0)
	{
		int parentIndex = (index + 1) / 2 - 1;

		if (values[index] < values[parentIndex])
			break;

		swap(values[parentIndex], values[index]);

		index = parentIndex;
	}

	siz++;
}


//pop
template<typename V>
void PriorityQueue<V>::pop()
{
	int index = 0;

	while (true)
	{
		int leftChildIndex = 2 * index + 1;
		int rightChildIndex = 2 * index + 2;

		if (leftChildIndex >= siz)
			break;

		if (rightChildIndex >= siz)
		{
			values[index] = values[leftChildIndex];
			index = leftChildIndex;
		}
		else if (values[rightChildIndex] < values[leftChildIndex])
		{
			values[index] = values[leftChildIndex];
			index = leftChildIndex;
		}
		else
		{
			values[index] = values[rightChildIndex];
			index = rightChildIndex;
		}
	}

	siz--;

	values[index] = values[siz];

	while (true)
	{
		if (index == 0) break;

		int parentIndex = (index + 1) / 2 - 1;

		if (values[index] < values[parentIndex])
			break;

		swap(values[parentIndex], values[index]);

		index = parentIndex;
	}
}

//capacity
template< typename V>
void PriorityQueue<V>::capacity(int cap)
{
	V* temp = new V[cap];
	int limit;
	if (cap < this->cap)
		limit = cap;
	else
		limit = this->cap;
	for (int i = 0; i < limit; i++)
		temp[i] = values[i];
	for (int i = limit; i < cap; i++)
		temp[i] = V();
	this->cap = cap;
	delete[] values;
	values = temp;
}

#endif