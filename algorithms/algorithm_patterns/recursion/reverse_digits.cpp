#include <iostream>
#include <print>

uint64_t reverse_num( uint64_t num ){
    if( num == 0 ){
        return 0;
    }
    return num % 10 + reverse_num( num/10 ) * 10;
}

auto main()->int 
{
    int N;
    while( true ){
        if( N == -1 ){
            break;
        }
        std::print("Please enter a number: " );
        std::cin >> N;
        std::cout << N << std::endl << reverse_num( N )<< std::endl;
    }
    return 0;
}