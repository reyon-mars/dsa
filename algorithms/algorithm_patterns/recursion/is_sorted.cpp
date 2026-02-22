#include <iostream>
#include <vector>


bool is_sorted( int arr[], int n ){
    if( n == 1 ){
        return true;
    }
    bool remaining_sorted = is_sorted( (arr+1), n-1 );
    return ( arr[0] < arr[1] && remaining_sorted );
}

int main(){
    int arr[10] = { 1, 2, 5, 52, 52, 3, 32, 35, 12, 5 };
    std::cout << std::boolalpha << is_sorted( arr, 10 );

    return 0;
}