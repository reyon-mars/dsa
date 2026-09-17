#pragma once
#include <cstddef>
#include <optional>

template <typename T>
class List 
{
private:
    std::size_t m_count{ 0 };
    T* m_items{ nullptr };

public:
    List();
    ~List();

    [[nodiscard]] std::optional<T> Get(std::size_t index) const;
    [[nodiscard]] std::size_t Count() const noexcept { return m_count; }

    [[nodiscard]] std::optional<std::size_t> Find(const T& value) const;

    void Insert(const T& value, std::size_t index);
    void Remove(const T& value);
    void Remove(std::size_t index);
};