#include "linked_list.hpp"

template <typename T>
Node<T>* LinkedList<T>::Get( std::size_t index ) const 
{
    if( index < 0 || index > m_count ) return nullptr;

    Node<T>* curr = Head;
    
    for( size_t i {0}; i < index; ++i )
    {
        curr = curr->next;
    }
    return curr;
}