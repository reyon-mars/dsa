#include <iostream>

int main(){

    int a(0), d(0), N(0);

    while( true ){
        std::cout << "Please enter the value for a : ";
        std::cin >> a;
        std::cout << "Please enter the value for d : ";
        std::cin >> d;
        std::cout << "Please enter the value for N : ";
        std::cin >> N;

        int n_term = a + ( N - 1 ) * d;

        std::cout << "The " << N << " term of the progression is " << n_term << std::endl;
    }

    return 0;
}

