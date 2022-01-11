#pragma once

template <typename T>
struct Node
{
	T value;
	Node* next;
};

template<typename T>
class Queue
{
private:
	Node<T>* head;
	Node<T>* tail;

public:
	explicit Queue();

	bool isEmpty() const;

	void enqueue(const T& value);

	T dequeue();

	T peek() const;

	void clear();

	~Queue();
};

template<typename T>
inline Queue<T>::Queue() :head{ nullptr }, tail{ nullptr }
{
}

template<typename T>
inline bool Queue<T>::isEmpty() const
{
	return this->head == nullptr;
}

template<typename T>
inline void Queue<T>::enqueue(const T& value)
{
	Node<T>* newNode = new Node<T>;
	newNode->value = value;
	newNode->next = nullptr;

	if (this->head == nullptr)
	{
		this->head = newNode;
	}
	else
	{
		this->tail->next = newNode;
	}

	this->tail = newNode;
}

template<typename T>
inline T Queue<T>::dequeue()
{
	T res = this->head->value;

	Node<T>* tmp = this->head;
	this->head = this->head->next;

	delete tmp;

	return res;
}

template<typename T>
inline T Queue<T>::peek() const
{
	return this->head->value;
}

template<typename T>
inline void Queue<T>::clear()
{
	Node<T>* tmp = this->head;

	while (tmp != nullptr)
	{
		tmp = tmp->next;
		delete this->head;
		this->head = tmp;
	}
}

template<typename T>
inline Queue<T>::~Queue()
{
	if (this->head)
		delete this->head;

	if (this->tail)
		delete this->head;
}
