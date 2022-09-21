#include "Linkedlist.h"
/*
template<class T>
inline Linkedlist<T>::Linkedlist()
{
	head = tail = 0;
	count = 0;
}

template <class T>
T Linkedlist<T>::At(int pos)
{
	assert(pos >= 0 && pos < count);
	Node<T>* tmp = head;
	for (int i = 0; i < pos; i++)
		tmp = tmp->next;
	return tmp->value;
}
template <class T>
void Linkedlist<T>::Append(T val)
{
	Node<T>* newNode = new Node<T>(val);
	if (head == 0)
		head = tail = newNode;
	else
	{
		tail->next = newNode;
		tail = newNode;

	}
	count++;
}
template <class T>
void Linkedlist<T>::DeleteAt(int pos)
{
	assert(pos >= 0 && pos < count);
	Node<T>* tmp = head;
	if (pos == 0)
	{
		head = head->next;
		delete tmp;
	}
	else
	{
		for (int i = 0; i < pos - 1; i++)
			tmp = tmp->next;
		Node<T>* del = tmp->next;
		tmp->next = del->next;
		delete del;
		if (pos == count - 1)
			tail = tmp;
	}
	count--;
}
*/