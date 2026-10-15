#include <algorithm>
#include <vector>

std::vector<std::vector<int>> threeSum(std::vector<int> nums)
{
	const int n{static_cast<int>(nums.size())};
	std::vector<std::vector<int>> result;

	if (n < 3)
		return result;

	result.reserve(n / 3 + 1);
	std::ranges::sort(nums);

	for (int i{0}; i < (n - 2); ++i)
	{
		if (nums[i] > 0)
			break;
		if (i > 0 && nums[i] == nums[i - 1])
			continue;

		int left{i + 1};
		int right{n - 1};

		while (left < right)
		{
			const long long sum{static_cast<long long>(nums[i]) + nums[left] + nums[right]};
			if (sum < 0)
				left++;
			else if (sum > 0)
				right--;
			else
			{
				result.push_back({nums[i], nums[left], nums[right]});
				++left, --right;
				while (left < right && nums[left] == nums[left - 1])
					left++;
				while (left < right && nums[right] == nums[right - 1])
					right--;
			}
		}
		return result;
	}
}