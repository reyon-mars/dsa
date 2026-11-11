#include <numeric>
#include <vector>

int pivotIndex(std::vector<int>& nums)
{
	const auto n{nums.size()};
	int sum{std::accumulate(nums.begin(), nums.end(), 0)};
	int currSum{0};

	for (size_t i{0}; i < n; ++i)
	{
		sum -= nums[i];
		if (currSum == sum)
		{
			return static_cast<int>(i);
		}
		currSum += nums[i];
	}
	return -1;
}