#include "linked_list.hpp"
#include "node.hpp"


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