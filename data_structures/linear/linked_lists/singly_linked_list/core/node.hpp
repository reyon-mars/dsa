#pragma once
#include <memory>

template <typename T>
struct Node
{
	T data;
	std::unique_ptr<Node<T>> next;

	Node(T val) : data(std::move(val)), next(nullptr)
	{
	}
	Node(T val, std::unique_ptr<Node<T>> next) : data(std::move(val)), next(std::move(next))
	{
	}

	Node(const Node&) = delete;
	Node& operator=(const Node&) = delete;

	Node(Node&&) noexcept = default;
	Node& operator=(Node&&) = default;
};