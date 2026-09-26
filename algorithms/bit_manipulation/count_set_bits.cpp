#include <atomic>
#include <bit>
#include <cstddef>
#include <cstdint>

std::size_t count_set_bits_std( int num )
{
    const auto u_num = static_cast< unsigned int> ( num );
    return std::popcount( u_num );
}

std::uint8_t count_set_bits( int num )
{
    std::uint8_t count { 0 };
    while( num )
    {
        count++;
        num = ( num & ( num -1 ) );
    }
    return count;
}

std::size_t find_pos_of_only_setbit( unsigned int value )
{
    return __builtin_ffs( value );
}
