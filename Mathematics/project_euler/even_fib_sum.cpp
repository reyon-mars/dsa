#include <ranges>
#include <iostream>
#include <print>
#include <array>
#include <algorithm>
#include <cstdint>

consteval std::array<uint64_t, 31> generate_even_fib()
{
    std::array<uint64_t, 31> even_fib{};

    uint64_t t1 = 0;
    uint64_t t2 = 2;

    even_fib[0] = t1;
    even_fib[1] = t2;

    for (std::size_t count = 2; count < 31; ++count)
    {
        uint64_t next_even = (4 * t2) + t1;
        even_fib[count] = next_even;

        t1 = t2;
        t2 = next_even;
    }

    return even_fib;
}

consteval std::array<uint64_t, 31> generate_prefix_sum(const std::array<uint64_t, 31> &arr)
{
    std::array<uint64_t, 31> prefix_sum{};

    prefix_sum[0] = arr[0];

    for (std::size_t i = 1; i < arr.size(); ++i)
    {
        prefix_sum[i] = arr[i] + prefix_sum[i - 1];
    }

    return prefix_sum;
}

static constexpr auto even_fibs = generate_even_fib();
static constexpr auto even_prefix_sum = generate_prefix_sum(even_fibs);

auto main(int argc, char *argv[]) -> int
{
    int T;
    std::print("Enter the number of tests: ");
    std::cin >> T;

    while (T--)
    {
        uint64_t N;
        std::print("Please enter a number: ");
        std::cin >> N;

        auto it = std::ranges::upper_bound(even_fibs, N);
        auto dist = std::distance(even_fibs.begin(), it);

        if (dist == 0)
        {
            std::println("0");
        }
        else
        {
            std::println("{}", even_prefix_sum[dist - 1]);
        }
    }
}
