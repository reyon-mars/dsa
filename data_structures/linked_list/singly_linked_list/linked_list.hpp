#pragma once
#include "node.hpp"
#include <cstddef>

template < typename T >
class LinkedList
{
    private:
        int m_count { 0 };
    
    public:
        Node<T>* Head{ nullptr };
        Node<T>* Tail{ nullptr };

        LinkedList();

        Node<T>* Get( std::size_t index ) const;

        
        void InsertHead( T val );
        void InsertTail( T val );
        void Insert( size_t index, T val );

        int Search( T val ) const;
        void RemoveHead();
        void RemoveTail();
        void RemoveFirst( T val );
        void Remove( size_t index );

        [[nodiscard]] size_t Count() const { return m_count; };
        void Print() const;
};
