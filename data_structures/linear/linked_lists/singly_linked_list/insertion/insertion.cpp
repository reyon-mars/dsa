#include "../node/node.hpp"

template <typename T>
auto insert_at_head(std::unique_ptr<Node<T>> head, T value) -> void
{
    auto temp = std::make_unique<Node<T>>(std::move(value));
    temp->next = std::move(head);
    head = std::move(temp);
}

template <typename T>
auto insert_at_tail(std::unique_ptr<Node<T>> head, T value) -> void
{
    if (!head)
    {
        head = std::make_unique<Node<T>>(std::move(value));
        return;
    }

    Node<T> *temp = head.get();
    while (temp->next)
    {
        temp = temp->next.get();
    }
    temp->next = std::make_unique<Node<T>>(std::move(value));
}