

size_t  count_set_bits( int n ){
    size_t count = 0;
    
    while( n ){
        n &= ( n - 1 );
        count++;
    }
    return count;
}