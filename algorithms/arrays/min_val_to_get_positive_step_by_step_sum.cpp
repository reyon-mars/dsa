#include <algorithm>
#include <vector>

int minStartValue(std::vector<int>& nums)
{
	int currSum{0};
	int minSum{0};
	for (const auto num : nums)
	{
		currSum += num;
		minSum = std::min(currSum, minSum);
	}
	return std::max(1, 1 - minSum);
}