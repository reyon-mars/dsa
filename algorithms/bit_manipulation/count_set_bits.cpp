#include <bit>
#include <cstddef>

std::size_t count_set_bits( int num )
{
    const auto u_num = static_cast< unsigned int> ( num );
    return std::popcount( u_num );
}