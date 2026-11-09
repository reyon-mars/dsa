#include <algorithm>
#include <vector>

int largest_stl(const std::vector<int>& vec)
{
	return *std::ranges::max_element(vec);
}

int largest(const std::vector<int>& vec)
{
	int largest_val{vec.front()};
	for (const auto num : vec)
	{
		largest_val = std::max(num, largest_val);
	}
	return largest_val;
}