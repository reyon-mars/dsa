#include <unordered_set>
#include <vector>

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2)
{
	std::unordered_set<int> numSet(nums1.begin(), nums2.end());
	std::vector<int> result{};

	for (const auto num : nums2)
	{
		if (numSet.erase(num))
		{
			result.push_back(num);
		}
	}
	return result;
}