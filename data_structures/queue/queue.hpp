#pragma once
#include <cstddef>
#include <stdexcept>
#include <utility>

template <typename T>
class Queue
{
private:
	struct Node
	{
		T data{};
		Node* next{nullptr};

		Node(T val) : data(std::move(val)) {};
	};
	std::size_t m_count{0};
	Node* m_front{nullptr};
	Node* m_back{nullptr};
	void Clear()
	{
		Node* currNode{m_front};
		Node* nextNode{nullptr};
		while (currNode)
		{
			nextNode = currNode->next;
			delete currNode;
			currNode = nextNode;
		}
		m_front = m_back = nullptr;
		m_count = 0;
	}

public:
	Queue() = default;
	~Queue()
	{
		Clear();
	}

	Queue(const Queue&) = delete;
	Queue& operator=(const Queue&) = delete;

	bool IsEmpty() const
	{
		return m_count == 0;
	}
	std::size_t Size() const
	{
		return m_count;
	}

	const T& Front() const;
	void Enqueue(T val);
	void Dequeue();
};

template <typename T>
const T& Queue<T>::Front() const
{
	if (IsEmpty())
		throw std::underflow_error("Invalid Operation: Front() on an empty queue is not defined.");
	return m_front->data;
}

template <typename T>
void Queue<T>::Enqueue(T val)
{
	Node* newNode{new Node(std::move(val))};
	if (IsEmpty())
	{
		m_front = m_back = newNode;
	}
	else
	{
		m_back->next = newNode;
		m_back = newNode;
	}
	m_count++;
}

template <typename T>
void Queue<T>::Dequeue()
{
	if (IsEmpty())
		throw std::underflow_error("Invalid Operation: Dequeuing an empty queue is not defined.");

	Node* oldFront{m_front};
	m_front = m_front->next;
	delete oldFront;
	if (!m_front)
		m_back = nullptr;
	m_count--;
}