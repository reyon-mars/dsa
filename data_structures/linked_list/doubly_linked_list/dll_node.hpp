#pragma once
#include <utility>

template <typename T>
class Node
{
public:
	T data{};
	Node<T>* previous{nullptr};
	Node<T>* next{nullptr};

	Node(T value) : data(std::move(value))
	{
	}
};