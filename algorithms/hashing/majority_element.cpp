#include <unordered_map>
#include <vector>

int majorityElement(const std::vector<int>& nums)
{
	const int n{static_cast<int>(nums.size())};
	std::unordered_map<int, int> freq{};
	freq.reserve(n / 2 + 1);

	for (const auto num : nums)
	{
		freq[num]++;
	}

	for (const auto [num, count] : freq)
	{
		if (count > n / 2)
		{
			return num;
		}
	}
	return -1;
}