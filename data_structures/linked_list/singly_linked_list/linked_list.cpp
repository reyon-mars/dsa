#include "linked_list.hpp"
#include "node.hpp"
#include <cstddef>


// Time complexity of O(N), since it has to iterate
// through the entire list it the index is that of
// the last Node.
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


// Time Complexity of O(1)
template <typename T>
void LinkedList<T>::InsertHead( T val )
{
    Node<T>* newNode { new Node<T>( val ) };

    newNode->next = Head;
    Head = newNode;
    if( !m_count )
    {
        Head = Tail;
    }
    m_count++;
}

// O(1)
template <typename T>
void LinkedList<T>::InsertTail( T val )
{
    if( m_count == 0 )
    {
        InsertHead( val );
        return;
    }
    
    Node<T>* newNode{ new Node<T>( val ) };
    Tail->next = newNode;
    Tail = newNode;
    m_count++;
    return;
}

template <typename T>
void LinkedList<T>::Insert( size_t index, T val )
{
    if( index < 0 || index > m_count ) return;

    if( index == 0 )
    {
        InsertHead(val );
        return;
    }
    else if( index == m_count )
    {
        InsertTail( val );
        return;
    }

    Node<T>* newNode { new Node<T>( val ) };
    Node<T>* prevNode { Head };
    
    for( size_t i = 0; i < ( index - 1 ); i++ )
    {
        prevNode = prevNode->next;
    }
    
    Node<T>* nextNode { prevNode->next };

    prevNode->next = newNode;
    newNode->next = nextNode;
    m_count++;
    
    return;
}