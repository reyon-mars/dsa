#include <cstddef>
#include <optional>
#include <print>

std::optional<unsigned int> set_bit( std::size_t position, unsigned int value  )
{
    if( position <  0 || position > 31 )
    {
        return std::nullopt;
    }

    return value | ( 1U << position );
}

bool check_ith_bit( std::size_t position, unsigned int value )
{
    if( position > 31 || position < 0 ) return false;
    
    return value & ( 1U << position );
}