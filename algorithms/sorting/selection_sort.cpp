#include <vector>
#include <iostream>
#include <concepts>

template <std::totally_ordered T>
void selection_sort(std::vector<T> &vec)
{
    size_t n = vec.size();
    size_t min_idx;

    for (size_t i = 0; i < n; i++)
    {
        min_idx = i;
        for (size_t j = i + 1; j < n; j++)
        {
            if (vec[j] < vec[min_idx])
            {
                min_idx = j;
            }
        }
        std::swap(vec[i], vec[min_idx]);
    }
}

auto main() -> int
{
    std::vector<int> v{1, 5, 25, 6, 2, 6, 36};
    selection_sort(v);

    for (auto num : v)
    {
        std::cout << num << " ";
    }
    return 0;
}