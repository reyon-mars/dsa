#include <iostream>

void print_till_N(int N)
{
    if (N <= 0)
    {
        return;
    }

    if (N == 1)
    {
        std::cout << N << " ";
        return;
    }
    print_till_N(N - 1);
    std::cout << N << " ";
}

void print_till_1(int N)
{
    if (N <= 0)
    {
        return;
    }
    if (N == 1)
    {
        std::cout << N << " ";
        return;
    }
    std::cout << N << " ";
    print_till_1(N - 1);
}

auto main() -> int
{
    int N;
    std::cout << "Please enter a number: ";
    std::cin >> N;
    std::cout << std::endl;

    print_till_N(N);
    print_till_1(N);

    return 0;
}