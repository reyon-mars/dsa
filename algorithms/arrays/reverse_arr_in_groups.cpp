#include <algorithm>
#include <vector>

std::vector<int> reverseInGroups(const std::vector<int>& vec, int k)
{
	const auto n{static_cast<int>(vec.size())};
	std::vector<int> result{vec};

	for (auto i{0}; i < n; i += k)
	{
		auto left{result.begin() + i};
		auto right{result.begin() + std::min(i + k, n)};
		std::ranges::reverse(left, right);
	}
	return result;
}