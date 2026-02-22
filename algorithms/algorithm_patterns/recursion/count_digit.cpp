#include <iostream>
#include <print>

uint32_t count_digit(int num)
{
    if (num == 0)
    {
        return 1;
    }
    if (num < 10)
    {
        return 1;
    }
    return 1 + count_digit(num / 10);
}

auto main() -> int
{
    int number;
    int count = 0;
    std::print("Please enter a number: ");
    std::cin >> number;

    count_digit(number);
    std::cout << number << " : " << count;

    return 0;
}