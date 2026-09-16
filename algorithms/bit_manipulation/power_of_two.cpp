#include <bit>
#include <climits>
#include <iostream>

bool power_of_2(int n) 
{ 
    return !(n & (n - 1)); 
}

bool powerOf2(int n) 
{
     return std::popcount(static_cast<unsigned int>(n)) == 1;
}

int main() 
{
    for( int i = 0; i <= INT_MAX; ++i )
    {
        std::cout << i << " is " << ( powerOf2(i)? " power of 2" : " not power of 2 " ) << '\n';
    }
  
    return 0;
}