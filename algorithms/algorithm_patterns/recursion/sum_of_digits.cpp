#include <iostream>

uint64_t sum_of_digits(uint64_t N)
{
    if (N == 0)
    {
        return 0;
    }

    return (N % 10) + sum_of_digits(N / 10);
}

auto main() -> int
{
    int N;

    while (true)
    {
        std::cout << "Please enter a number: ";
        std::cin >> N;

        std::cout << "Digits sum: " << sum_of_digits(N) << std::endl;
    }
    return 0;
}