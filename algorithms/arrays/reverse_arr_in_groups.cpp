#include <algorithm>
#include <vector>

std::vector<int> reverseInGroups(const std::vector<int>& vec, int k)
{
	const auto n{static_cast<int>(vec.size())};
	std::vector<int> result{vec};

	for (auto i{0}; i < n; ++i)
	{
		int left{i};
		int right{i + k};
		right = std::min(right, n);
		std::reverse(result.begin() + left, result.begin() + right);
	}
	return result;
}