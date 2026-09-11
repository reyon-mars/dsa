#include <ranges>

bool linearSearch(const std::ranges::forward_range auto &container, const auto &target) 
{
    for( const auto& elem : container )
    {
        if( elem == target ) return true;
    }
    return false;
}