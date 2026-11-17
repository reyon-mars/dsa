#include <numeric>
#include <vector>

std::vector<int> leftRightDifference(const std::vector<int>& nums)
{
	const auto n{static_cast<int>(nums.size())};
	auto leftSum{0};
	auto rightSum{std::accumulate(nums.begin(), nums.end(), 0)};
	std::vector<int> result{};
	result.reserve(n);

	for (const auto num : nums)
	{
		rightSum -= num;
		result.emplace_back(std::abs(leftSum - rightSum));
		leftSum += num;
	}
	return result;
}