#include <vector>

int majorityElement(const std::vector<int>& nums)
{
	int candidate{0};
	int count{0};

	for (const auto num : nums)
	{
		if (count == 0)
		{
			candidate = num;
		}
		count += (candidate == num ? 1 : -1);
	}
	return candidate;
}