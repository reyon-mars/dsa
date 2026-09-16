#include <print>
#include <string>

std::string reverse( std::string s ) 
{
    int front { 0 };
    int back { static_cast<int>(s.size() - 1) };

    while( front < back )
    {
        std::swap( s[front], s[back] );
        front++;
        back--;
    }
    return s;
}