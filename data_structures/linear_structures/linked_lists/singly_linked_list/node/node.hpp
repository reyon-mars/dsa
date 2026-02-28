#pragma once
#include <memory>

template <typename T>
struct node
{
    T data;
    std::unique_ptr<node<T>> next;

    explicit node(T value) : data(std::move(value)), next(nullptr) {}
};

template <typename T>
using Node = struct node<T>;