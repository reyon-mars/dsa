#include <iostream>

uint64_t factorial( uint64_t N ){
    if( N == 1 ){
        return 1;
    }
    return N * factorial( N - 1 );
}

auto main()->int
{
    int N;
    std::cout << "Please enter a number: ";
    std::cin >> N;
    std::cout << std::endl << factorial( N );
    return 0;
}