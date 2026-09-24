#include <cstddef>
#include <optional>

std::optional<unsigned int> clear_ith_bit( std::size_t position, unsigned int value  )
{
    if( position > 31 || position < 0 ) 
    {
        return std::nullopt;
    }

    return value & ~( 1U << position );
}

std::optional<unsigned int> toggle_ith_bit( std::size_t position, unsigned int )