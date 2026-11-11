#include <vector>

std::vector<int> runningSum(const std::vector<int>& nums)
{
	std::vector<int> result{};
	result.reserve(nums.size());
	int currSum{0};

	for (const auto num : nums)
	{
		currSum += num;
		result.push_back(currSum);
	}
	return result;
}