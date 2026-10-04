#pragma once
#include "node.hpp"
#include <cstddef>

template <typename T>
class LinkedList
{
private:
	std::size_t m_count{0};

public:
	Node<T>* Head{nullptr};
	Node<T>* Tail{nullptr};

	LinkedList() {};

	Node<T>* Get(std::size_t index) const;

	void InsertHead(T val);
	void InsertTail(T val);
	void Insert(size_t index, T val);

	int Search(T val) const;
	void RemoveHead();
	void RemoveTail();
	void RemoveFirst(T val);
	void Remove(size_t index);

	[[nodiscard]] size_t Count() const
	{
		return m_count;
	};
	void Print() const;
};

#pragma once
#include "linked_list.hpp"
#include "node.hpp"
#include <cstddef>
#include <print>

// Time complexity of O(N), since it has to iterate
// through the entire list it the index is that of
// the last Node.
template <typename T>
Node<T>* LinkedList<T>::Get(std::size_t index) const
{
	if (index < 0 || index > m_count)
		return nullptr;

	Node<T>* curr = Head;

	for (size_t i{0}; i < index; ++i)
	{
		curr = curr->next;
	}
	return curr;
}

// Time Complexity of O(1)
template <typename T>
void LinkedList<T>::InsertHead(T val)
{
	Node<T>* newNode{new Node<T>(val)};

	newNode->next = Head;
	Head = newNode;
	if (!m_count)
	{
		Tail = Head;
	}
	m_count++;
}

// O(1)
template <typename T>
void LinkedList<T>::InsertTail(T val)
{
	if (m_count == 0)
	{
		InsertHead(val);
		return;
	}

	Node<T>* newNode{new Node<T>(val)};
	Tail->next = newNode;
	Tail = newNode;
	m_count++;
	return;
}

// Time Complexity : O(N)
// Best Case : O(1)
template <typename T>
void LinkedList<T>::Insert(size_t index, T val)
{
	if (index < 0 || index > m_count)
		return;

	if (index == 0)
	{
		InsertHead(val);
		return;
	}
	else if (index == m_count)
	{
		InsertTail(val);
		return;
	}

	Node<T>* newNode{new Node<T>(val)};
	Node<T>* prevNode{Head};

	for (size_t i = 0; i < (index - 1); i++)
	{
		prevNode = prevNode->next;
	}

	Node<T>* nextNode{prevNode->next};

	prevNode->next = newNode;
	newNode->next = nextNode;
	m_count++;

	return;
}

// Time Complexity: O(N)
// Best Case: O(1)
template <typename T>
int LinkedList<T>::Search(T val) const
{
	if (!m_count)
		return -1;

	const Node<T>* temp = Head;

	for (size_t i = 0; i < m_count && temp; ++i, temp = temp->next)
	{
		if (temp->data == val)
		{
			return static_cast<int>(i);
		}
	}
	return -1;
}

// O(1)
template <typename T>
void LinkedList<T>::RemoveHead()
{
	if (m_count == 0)
	{
		return;
	}

	Node<T>* node{Head};

	Head = Head->next;
	delete node;
	m_count--;
}

// O(N)
template <typename T>
void LinkedList<T>::RemoveTail()
{
	if (m_count == 0)
	{
		return;
	}

	if (m_count == 1)
	{
		RemoveHead();
		return;
	}

	Node<T>* prevNode{Head};

	while (prevNode && prevNode->next != Tail)
	{
		prevNode = prevNode->next;
	}

	prevNode->next = nullptr;
	delete Tail;
	Tail = prevNode;

	m_count--;
}

// O(N)
template <typename T>
void LinkedList<T>::Remove(size_t index)
{
	if (m_count == 0)
		return;

	if (index >= m_count)
		return;

	if (index == 0)
	{
		RemoveHead();
		return;
	}
	else if (index == (m_count - 1))
	{
		RemoveTail();
		return;
	}

	Node<T>* prevNode{nullptr};
	Node<T>* currNode{Head};

	for (size_t i = 0; i < index && currNode; i++, currNode = currNode->next)
		prevNode = currNode;

	prevNode->next = currNode->next;
	delete currNode;
	m_count--;
}

template <typename T>
void LinkedList<T>::Print() const
{
	for (auto curr{Head}; curr != nullptr; curr = curr->next)
	{
		std::print(" {} ->", curr->data);
	}
	std::print("nullptr");
}
