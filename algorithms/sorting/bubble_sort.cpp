#include <iostream>
#include <vector>

template < typename T >
void bubble_sort( std::vector<T>& vec ){

    if( vec.empty() ){
        return ;
    }

    size_t n = vec.size();
    bool swap_occured;

    for( size_t i = 0; i < n - 1; i++ ){
        swap_occured = false;

        for( size_t j = 0; j < n - i - 1; j++ ){
            if( vec[j] > vec[j+1] ){
                std::swap( vec[j], vec[j+1] );
                swap_occured = true;
            }
        }
        if( !swap_occured ){
            break;
        }
    }
}

auto main()->int 
{
    std::vector<int> v{ 2, 3, 6, 2, 3, 52, 1, };

    bubble_sort( v );
    
    for( auto num: v ){
        std::cout << num << " ";
    }
    return 0;
}