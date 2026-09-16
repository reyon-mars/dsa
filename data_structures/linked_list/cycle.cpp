#include "../core/list.hpp"


template<typename T >
bool cyclePresent( List<T>& list )
{
    if( list.empty() ) return false;
    
    const auto slow = list.head.get();
    const auto fast = list.head.get();
    
    while( fast != nullptr && fast->next != nullptr )
    {
        slow = slow->next.get();
        fast = fast->next->next.get();

        if( fast == slow ) 
        {
            return true;
        }
    }
    
    return false;
}