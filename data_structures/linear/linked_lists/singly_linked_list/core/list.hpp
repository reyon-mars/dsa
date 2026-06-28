#pragma once
#include "node.hpp"
#include <cstddef>
#include <memory>
#include <stdexcept>
#include <string>
#include <string_view>

constexpr std::string_view OUT_OF_RANGE_ERR = "List index out of bounds.";

template <typename T>
class List
{
private:
	std::unique_ptr<Node<T>> head;
	Node<T>* tail;
	size_t size{0};

public:
	List() : head(nullptr), tail(nullptr)
	{
	}
	~List() = default;

	size_t length() const
	{
		return size;
	};
	T& value(size_t pos);
	T value(size_t pos) const;
	bool empty() const
	{
		return size == 0;
	}
	void append(T value);
	void remove(size_t pos);
	void deleteAll(T value);
	void insertBefore();
	template <typename Fn>
	void apply(Fn ApplyFunction);
	template <typename Fn, typename Result>
	Result reduce(Fn ReduceFunction);
	void print() const;
};

template <typename T>
T& List<T>::value(size_t pos)
{
	if (pos >= size)
		throw std::out_of_range(std::string(OUT_OF_RANGE_ERR));

	Node<T>* curr = head.get();
	while (pos--)
	{
		curr = curr->next.get();
	}
	return curr->data;
}

template <typename T>
T List<T>::value(size_t pos) const
{
	if (pos >= size)
		throw std::out_of_range(std::string(OUT_OF_RANGE_ERR));

	Node<T>* curr = head.get();
	while (pos--)
	{
		curr = curr->next.get();
	}
	return curr->data;
}

template <typename T>
void List<T>::append(T value)
{
	auto temp = std::make_unique<Node<T>>(std::move(value));
	auto raw_ptr = temp.get();

	!head ? head = std::move(temp) : tail->next = std::move(temp);
	tail = raw_ptr;
	size++;
}

template <typename T>
void List<T>::remove(size_t pos)
{
	if (empty())
		return;
	if (pos >= size)
		throw std::out_of_range(std::string(OUT_OF_RANGE_ERR));

	if (pos == 0)
	{
		head = std::move(head->next);
		if (!head)
			tail = nullptr;
		size--;
		return;
	}

	Node<T>* prev = nullptr;
	Node<T>* curr = head.get();

	for (size_t i = 0; i < pos; i++)
	{
		prev = curr;
		curr = curr->next.get();
	}

	if (curr == tail)
	{
		tail = prev;
	}

	prev->next = std::move(curr->next);
	size--;
}

template <typename T>
template <typename Fn>
void List<T>::apply(Fn ApplyFunction)
{
	Node<T>* curr = head.get();
	while (curr)
	{
		ApplyFunction(curr->data);
		curr = curr->next.get();
	}
}