#include <iostream>

bool power_of_2( int n ){
    return ! ( n & ( n - 1 ) ); 
}

int main( void ) 
{
    for( int i = 1; i < (1ULL << 32 ); i = (2 * i ) ){
        std::cout << i << " " << ( power_of_2(i) ? "True": "False" ) << std::endl;
    }
    for( int i = 1; i <= 256 ; i++ ){
        if( power_of_2( i ) ) {
            std::cout << i << std::endl;
        }
    }
    return 0;
}