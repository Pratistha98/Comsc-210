#pragma once
//Programer      : Pratistha Maharjan
//Programmer's ID: 1650717
#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include <queue>

template<typename K, typename V>
class BinarySearchTree
{
	struct Node
	{
		K key;
		V value;
		Node* left;
		Node* right;
	};

	Node* rootNode;
	int siz;
	void keys(const Node*, queue<K> &) const;
	void clear(Node*);
	void copyTree(Node*, const Node*);

public:
	BinarySearchTree() { rootNode = 0; siz = 0; } //default constructor
	BinarySearchTree(const BinarySearchTree&);  //copy constructor
	BinarySearchTree<K, V> operator = (const BinarySearchTree<K, V>&);
	~BinarySearchTree(); //destructor

	int size() { return siz; }
	V operator[] (const K&) const; //getter
	V& operator[] (const K&);  //setter
	bool containsKey(const K&) const const; //getter
	void deleteKey(const K&); //setter
	queue<K> Keys() const;
	void clear();
private:
	void keys(const Node*, queue<K>&) const;
}


//square bracket[] getter
template<typename K, typename V>

V BinarySearchTree<K, V>::operator[](const K& key) const
{
	Node* p = rootNode;
	while (p)
	{
		if (p->key == key) break; //found it
		if (p->key < key) p = p->right;
		else p = p->left;
	}
	if (p) return p->value;

	return V();
}

//contains key getter
template<typename K, typename V>
bool BinarySearchTree<K, V>::containsKey(const K& key) const
{
	Node* p = rootNode;
	while (p)
	{
		if (p->key == key) break;
		if (p->key < key) p = p->right;
		else p = p->left;
	}
	return p != 0;
}

//keys()
template<typename K, typename V>
queue<K> BinarySearchTree<K, V>::keys() const
{
	queue<K> result;
	keys(rootNode, result);
	return result;
}

//clear()
template<typename K, typename V>


Node* p = rootNode;
Node* prev = 0;

while (p)
{
	if (p->key == key)
}
#endif