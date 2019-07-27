////Programmar: Pratistha Maharjan
////Programmar's Id: 1650717

#ifndef Queue_h
#define Queue_h

template<typename V>
class Queue
{
	struct Node
	{
		V value;
		Node* next;
	};
	int siz;
	Node* firstNode;
	Node* lastNode;

public:
	Queue();
	Queue(const Queue&);
	Queue<V>& operator = (const Queue<V>&);
	~Queue();
	void push(const V&);
	V& front();
	V& back();
	void pop();
	void clear();
	int size() const { return siz; }
	bool empty() const { return siz == 0 ? true : false; }
};

template<typename V>
Queue<V>::Queue()
{
	firstNode = 0;
	lastNode = 0;
	siz = 0;
}

template<typename V>
Queue<V>::Queue(const Queue<V>& original)
{
	firstNode = 0;
	lastNode = 0;
	siz = original.siz;
	for (Node* p = original.firstNode; p; p = p->next)
	{
		Node* temp = new Node;
		temp->value = p->value;
		temp->next = 0;
		if (lastNode) lastNode->next = temp;
		else firstNode = temp;
		lastNode = temp;
	}
}

template<typename V>
Queue<V>& Queue<V>::operator = (const Queue<V>& orig)
{
	if (this != &orig)
	{
		while (firstNode)
		{
			Node* p = firstNode->next;
			delete firstNode;
			firstNode = p;
		}
		lastNode = 0;
		for (Node* p = orig.firstNode; p; p = p->next)
		{
			Node* temp = new Node;
			temp->value = p->value;
			temp->next = 0;
			if (lastNode) lastNode->next = temp;
			else firstNode = temp;
			lastNode = temp;
		}
		siz = orig.siz;
	}
	return *this;
}

template<typename V>
Queue<V>::~Queue()
{
	while (firstNode)
	{
		Node* p = firstNode;
		firstNode = firstNode->next;
		delete p;
	}
}

template<typename V>
void Queue<V>::push(const V& value)
{
	Node* temp = new Node{ value };
	temp->value = value;
	temp->next = 0;
	if (lastNode) lastNode->next = temp;
	else firstNode = temp;
	lastNode = temp;
	++siz;
}

template<typename V>
V& Queue<V>::front()
{
	return firstNode->value;
}

template<typename V>
V& Queue<V>::back()
{
	return lastNode->value;
}


template<typename V>
void Queue<V>::pop()
{
	if (firstNode)
	{
		Node* p = firstNode;
		firstNode = firstNode->next;
		delete p;
		--siz;
	}
	if (siz == 0) lastNode = 0;
}

template<typename V>
void Queue<V>::clear()
{
	while (firstNode)
	{
		Node* p = firstNode;
		firstNode = firstNode->next;
		delete p;
		--siz;
	}
	firstNode = 0;
	lastNode = 0;
}

#endif
