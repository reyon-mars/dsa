#include <iostream>

uint64_t power( uint64_t base, uint64_t exp ){
    if( exp == 0 ){
        return 1;
    }
    return base * power( base, (exp-1 ) );
    
}

auto main()->int
{
    int base, exp;
    while( true ){
        std::cout << "Please enter the base: ";
        std::cin >> base;
        std::cout << "Please enter the exponent: " ;
        std::cin >> exp;
        std::cout << power( base, exp ) << std::endl;
    }
   

    return 0;
}