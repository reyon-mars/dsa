#include <iostream>

uint64_t sum_of_n_natural( uint64_t N )
{
    if( N == 1 ){
        return N;
    }
    return N + sum_of_n_natural( N-1 );
}


int main(){
    int N;
    std::cout << "Please enter a number: " ;
    std::cin >> N;
    std::cout << std::endl;

    std::cout << sum_of_n_natural( N );
    return 0;
}