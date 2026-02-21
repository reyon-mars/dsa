#include <iostream>
#include <cstdint>

constexpr uint64_t sum_divisible_by( uint64_t num, uint64_t limit )
{
    uint64_t k = ( limit -  1 ) / num;
    return num * k * ( k + 1 ) / 2;
}

constexpr uint64_t solve( uint64_t N ){
    return sum_divisible_by( 3, N ) +
           sum_divisible_by( 5, N ) -
           sum_divisible_by( 15,N );
}

auto main()-> int 
{
    uint64_t N;
    std::cin >> N;

    std::cout << solve(N) << std::endl;

    return 0;
}