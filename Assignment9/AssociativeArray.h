//Programmer     : Pratistha Maharjan
//Programmer's ID: 1650717
#ifndef AssociativeArray_h
#define AssociativeArray_h

#include <queue>

using namespace std;

template<typename K, typename V>
class AssociativeArray
{
	struct Node
	{
		K key;
		V value;
		bool inUse;
	};

	Node* data;
	int siz = 0;
	int cap = 0;
	void capacity(int);

public:
	AssociativeArray(int = 2);
	AssociativeArray(const AssociativeArray<K, V>&);
	AssociativeArray<K, V>& operator = (const AssociativeArray<K, V>&);
	~AssociativeArray() { clear(); }
	V& operator[](const K&) const;
	V& operator[](const K&);
	bool containsKey(const K&) const;
	void deleteKey(const K&);
	queue<K> keys() const;
	int size() const { return siz; }
	void clear();
};

//constructor
template <typename K, typename V>
AssociativeArray<K, V>::AssociativeArray(int cap)
{
	this->cap = cap;
	data = new Node[cap];
	for (int i = 0; i < cap; i++)
		data[i].inUse = false;
}

//copy constructor
template<typename K, typename V>
AssociativeArray<K, V>::AssociativeArray(const AssociativeArray<K, V>& original)
{
	siz = original.siz;
	data = new Node[cap];
	for (int i = 0; i < cap; i++)
		data[i] = original.data[i];
}

//assignment operator
template<typename K, typename V>
AssociativeArray<K, V>& AssociativeArray<K, V>::operator = (const AssociativeArray<K, V>& original)
{
	if (this != &original)
	{
		delete[] data;
		cap = original.cap;
		siz = original.siz;
		data = new Node[cap];
		for (int i = 0; i < cap; i++)
			data[i] = original.data[i];
	}
	return *this;
}

//square bracket operator getter
template<typename K, typename V>
V& AssociativeArray<K, V>::operator[](const K& key) const
{
	for (int i = 0; i < cap; ++i)
	{
		if (data[i].inUse && data[i].key == key)
			return data[i].value;
	}
	return V();
}

//square bracket operator setter
template<typename K, typename V>
V& AssociativeArray<K, V>::operator[](const K& key)
{
	int indexOfFirstUnusedKey = cap;
	for (int index = 0; index < cap; index++)
	{
		if (data[index].inUse)
		{
			if (data[index].key == key)
				return data[index].value;
		}
		else
		{
			indexOfFirstUnusedKey = index;
			break;
		}
	}


	if (indexOfFirstUnusedKey == cap) capacity(2 * cap);
	data[indexOfFirstUnusedKey].key = key;
	data[indexOfFirstUnusedKey].value = V();
	data[indexOfFirstUnusedKey].inUse = true;
	++siz;
	return data[indexOfFirstUnusedKey].value;
}

//keys getter
template <typename K, typename V>
queue<K> AssociativeArray<K, V>::keys() const
{
	queue<K> k_queue;
	for (int i = 0; i < cap; ++i)
	{
		if (data[i].inUse)
			k_queue.push(data[i].key);
	}
	return k_queue;
}

//contains key getter
template <typename K, typename V>
bool AssociativeArray<K, V>::containsKey(const K& key) const
{
	for (int i = 0; i < cap; i++)
	{
		if (data[i].inUse && data[i].key == key)
			return true;
	}
	return false;
}

//delete setter
template <typename K, typename V>
void AssociativeArray<K, V>::deleteKey(const K& key)
{
	for (int i = 0; i < cap; i++)
	{
		if (data[i].key == key)
		{
			data[i].inUse = false;
			siz--;
			return;
		}
	}
}

//clear setter
template <typename K, typename V>
void AssociativeArray<K, V>::clear()
{
	for (int i = 0; i < cap; i++)
	{
		data[i].inUse = false;
	}
	siz = 0;
	delete[] data;
}

//private capacity setter
template<typename K, typename V>
void AssociativeArray<K, V>::capacity(int cap)
{
	Node* temp = new Node[cap];
	int limit;
	if (cap < this->cap)
		limit = cap;
	else
		limit = this->cap;
	for (int i = 0; i < limit; i++)
		temp[i] = data[i];
	for (int i = limit; i < cap; i++)
	{
		temp[i].inUse = false;
		temp[i].key = K();
		temp[i].value = V();
	}
	this->cap = cap;
	delete[] data;
	data = temp;
}

#endif
