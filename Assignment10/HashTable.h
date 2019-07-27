//Programmer     : Pratistha Maharjan 
//Programmer's ID: 1650717
#ifndef HashTable_h
#define HashTable_h

#include <list>
#include <string>
#include <queue>

using namespace std;

#include <cmath>

template <typename K, typename V, int cap>
class HashTable
{
	struct Node
	{
		K key = K();
		V value = V();
	};

	list<Node> data[cap]; //chaining
	int(*hashCode)(const K&); //ptr to hashCode function
	int siz = 0;   //occupied elements in array
	int n_siz = 0;//total nodes

public:
	HashTable(int(*)(const K&) = 0);
	double loadFactor() const { return 1.0 * siz / cap; }
	double node_loadFactor()  const { return 1.0 * n_siz / cap; }
	V operator[](const K&) const;
	V& operator[](const K&);
	bool containsKey(const K&) const;
	void deleteKey(const K&);
	queue<K> keys() const;
	int size() const { return siz; }
	void clear();
};

//main constructor
template<typename K, typename V, int cap>
HashTable<K, V, cap>::HashTable(int(*hashCode) (const K&))
{
	this->hashCode = hashCode;
	siz = cap;
}


template <typename K, typename V, int cap>
V HashTable<K, V, cap>::operator[](const K& key) const //getter
{
	int index = hashCode(key) % cap;
	if (index < 0) index += cap;
	typename list<Node>::const_iterator it;
	for (it = data[index].begin(); it != data[index].end(); it++)
		if (it->key == key) return it->value;
	return V();
}

template <typename K, typename V, int cap>
V& HashTable<K, V, cap>::operator[](const K& key) //setter
{
	int index = hashCode(key) % cap;
	if (index < 0) index += cap;

	typename list<Node>::iterator it;
	for (it = data[index].begin(); it != data[index].end(); it++)
		if (it->key == key) return it->value;

	//create new Node to list
	if (data[index].empty()) siz++;
	Node temp;
	temp.key = key;
	temp.value = V();
	data[index].push_back(temp);
	n_siz++;
	return data[index].back().value;
}

template <typename K, typename V, int cap>
bool HashTable<K, V, cap>::containsKey(const K& key) const
{
	int index = hashCode(key) % cap;
	if (index < 0) index += cap;
	typename list<Node>::const_iterator it;
	for (it = data[index].begin(); it != data[index].end(); it++)
		if (it->key == key) return true;
	return false;
}

template <typename K, typename V, int cap>
void HashTable<K, V, cap>::deleteKey(const K& key)
{
	int index = hashCode(key) % cap;
	if (index < 0) index += cap;
	typename list<Node>::const_iterator it;
	for (it = data[index].begin(); it != data[index].end(); it++)
		if (it->key == key)
		{
			data[index].erase(it);
			break;
		}
	if (data[index].empty()) siz--;
}

template<typename K, typename V, int cap>
queue<K> HashTable<K, V, cap>::keys() const
{
	queue<K> rkeys;
	typename list<Node>::const_iterator it;
	for (int i = 0; i < cap; i++)
	{
		for (it = data[i].begin(); it != data[i].end(); it++)
			rkeys.push(it->key);
	}
	return rkeys;
}

template <typename K, typename V, int cap>
void HashTable<K, V, cap>::clear()
{
	for (int i = 0; i < cap; i++)
		data[i].clear();
	siz = 0;
}

#endif
