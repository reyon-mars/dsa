#pragma once
#include "node.hpp"
#include <cstddef>
#include <functional>
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
	void append();
	void remove();
	void deleteAll();
	void insertBefore();
	void apply(std::function<void()>& ApplyFunction);
	void reduce(std::function<void()>& ReduceFunction);
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
