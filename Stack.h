#pragma once

template <typename T>
struct Node
{
	T value;
	Node* prev;
};

template <typename T>
class Stack
{
private:
	Node<T>* tail;

public:
	explicit Stack();

	void push(const T& value);

	T pop();

	T peek() const;

	bool isEmpty() const;

	void clear();

	~Stack();
};

template<typename T>
inline Stack<T>::Stack() :tail(nullptr)
{

}

template<typename T>
inline void Stack<T>::push(const T& value)
{
	Node<T>* newNode = new Node<T>;
	newNode->value = value;
	newNode->prev = this->tail;
	
	this->tail = newNode;
}

template<typename T>
inline T Stack<T>::pop()
{
	T res = this->tail->value;

	Node<T>* tmp = this->tail;

	this->tail = this->tail->prev;

	delete tmp;

	return res;
}

template<typename T>
inline T Stack<T>::peek() const
{
	return this->tail->value;
}

template<typename T>
inline bool Stack<T>::isEmpty() const
{
	return this->tail == nullptr;
}

template<typename T>
inline void Stack<T>::clear()
{
	Node<T>* tmp = this->tail;

	while (tmp != nullptr)
	{
		tmp = tmp->prev;
		delete this->tail;
		this->tail = tmp;
	}
}

template<typename T>
inline Stack<T>::~Stack()
{
	if (this->tail)
		delete this->tail;
}
