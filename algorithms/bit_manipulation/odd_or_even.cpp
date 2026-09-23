#include <print>

inline int is_odd( int n )
{
    return static_cast<unsigned int>( n ) & 1 ;
}

int is_even( int n )
{
    return !is_odd( n );
}