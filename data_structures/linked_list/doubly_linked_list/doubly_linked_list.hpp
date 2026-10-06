#pragma once
#include "dll_node.hpp"
#include <cstddef>

template <typename T>
class DoublyLinkedList
{
private:
	size_t m_count{0};
	Node<T>* Head{nullptr};
	Node<T>* Tail{nullptr};

public:
	DoublyLinkedList() = default;

	Node<T>* Get(size_t index) const;

	void InsertHead(T value);
	void InsertTail(T value);
	void Insert(size_t index, T value);

	int Search(T value) const;

	void RemoveHead();
	void RemoveTail();
	void Remove(size_t index);

	size_t Size() const
	{
		return m_count;
	};
	void Print() const;
	void PrintReverse() const;
};

template <typename T>
void DoublyLinkedList<T>::RemoveHead()
{
	if (m_count == 0)
		return;

	Node<T>* oldHead = Head;
	Head = Head->next;

	if (Head)
		Head->previous = nullptr;
	else
		Tail = nullptr;

	delete oldHead;
	m_count--;
}

template <typename T>
void DoublyLinkedList<T>::RemoveTail()
{
	if (m_count == 0)
		return;

	if (m_count == 1)
	{
		RemoveHead();
		return;
	}

	Node<T>* oldTail = Tail;
	Tail = Tail->previous;
	Tail->next = nullptr;
	delete oldTail;

	m_count--;
}

template <typename T>
void DoublyLinkedList<T>::Remove(size_t index)
{
	if (index < 0 || index >= m_count)
		return;

	if (index == 0)
	{
		RemoveHead();
		return;
	}
	if (index == m_count - 1)
	{
		RemoveTail();
		return;
	}

	Node<T>* currNode{Head};
	for (size_t idx = 0; idx < index; ++idx, currNode = currNode->next)
	{
	};
	Node<T>* prevNode{currNode->previous};
	Node<T>* nextNode{currNode->next};
	prevNode->next = nextNode;
	nextNode->previous = prevNode;
	delete currNode;
	--m_count;
	return;
}

template <typename T>
void DoublyLinkedList<T>::InsertHead(T value)
{
	Node<T>* newNode{new Node<T>(value)};
	newNode->next = Head;

	if (Head)
	{
		Head->previous = newNode;
	}

	Head = newNode;
	if (m_count == 0)
	{
		Tail = Head;
	}
	m_count++;
	return;
}

template <typename T>
void DoublyLinkedList<T>::InsertTail(T value)
{
	if (m_count == 0)
	{
		InsertHead(value);
		return;
	}

	Node<T>* newNode{new Node<T>(value)};
	newNode->previous = Tail;
	Tail->next = newNode;
	Tail = newNode;
	m_count++;
	return;
}

template <typename T>
void DoublyLinkedList<T>::Insert(size_t index, T value)
{
	if (index < 0 || index >= m_count)
		return;

	if (index == 0)
	{
		InsertHead(value);
		return;
	}
	else if (index == m_count)
	{
		InsertTail(value);
		return;
	}

	Node<T>* newNode{new Node<T>(value)};
	Node<T>* prevNode{Head};

	for (size_t idx = 0; idx < (index - 1); ++idx, prevNode = prevNode->next)
	{
	};

	Node<T>* nextNode{prevNode->next};
	prevNode->next = newNode;
	nextNode->previous = newNode;
	newNode->previous = prevNode;
	newNode->next = nextNode;
	m_count++;
}

template <typename T>
int DoublyLinkedList<T>::Search(T val) const
{
	if (m_count == 0)
		return -1;

	Node<T>* currNode{Head};
	for (size_t idx = 0; idx < m_count, currNode; ++idx, currNode = currNode->next)
	{
		if (currNode->data == val)
		{
			return idx;
		}
	}
	return -1;
}