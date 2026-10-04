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

	size_t Size() const;
	void Print() const;
	void PrintReverse() const;
};

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

	auto node = Tail;
	Tail = Tail->previous;
	Tail->next = nullptr;
	delete node;

	m_count--;
}