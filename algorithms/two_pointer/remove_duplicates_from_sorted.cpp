#include <vector>

int removeDuplicates(std::vector<int>& nums)
{
	if (nums.empty())
		return 0;

	const int n{static_cast<int>(nums.size())};
	int write_idx{1};

	for (int i{1}; i < n; ++i)
	{
		if (nums[i - 1] != nums[i])
		{
			nums[write_idx] = nums[i];
			write_idx++;
		}
	}
	return write_idx;
}