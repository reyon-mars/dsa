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
        [[nodiscard]] std::optional<T> Get( size_t index ) const;
        [[nodiscard]] std::size_t Count() const { return m_count; };

        [[nodiscard]] std::optional<T> Find( const T& value ) const;

        void Insert( const T& value, size_t index );
        void Remove( const T& value );
        void Remove( size_t index );

};