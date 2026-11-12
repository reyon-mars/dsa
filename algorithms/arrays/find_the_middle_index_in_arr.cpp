#include <numeric>
#include <vector>

int findMiddleIndex(const std::vector<int>& nums)
{
	const auto n{nums.size()};
	long long totalSum{std::accumulate(nums.begin(), nums.end(), 0LL)};
	int leftSum{0};

	for (size_t i{0}; i < n; ++i)
	{
		totalSum -= nums[i];
		if (totalSum == leftSum)
		{
			return i;
		}
		leftSum += nums[i];
	}
	return -1;
}