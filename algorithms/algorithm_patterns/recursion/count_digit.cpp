#include <iostream>
#include <print>

void count_digit(int num, int &count)
{
    if (num == 0)
    {
        return;
    }
    count_digit((num / 10), count);
    count++;
}

auto main() -> int
{
    int number;
    int count = 0;
    std::print("Please enter a number: ");
    std::cin >> number;

    count_digit(number, count);
    std::cout << number << " : " << count;

    return 0;
}