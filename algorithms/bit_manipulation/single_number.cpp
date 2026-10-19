#include <numeric>
#include <vector>

int find_unique_elem( std::vector<int>& vec )
{
    return std::accumulate( vec.begin(), vec.end(), 0, std::bit_xor<int>() );
}