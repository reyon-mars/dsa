#include <algorithm>
#include <utility>
#include <vector>

class NumArray
{
private:
	std::vector<int> prefixSum{};

public:
	NumArray(std::vector<int> nums) : prefixSum(std::move(nums))
	{
		auto currSum{0};
		for (auto& num : prefixSum)
		{
			currSum += num;
			num = currSum;
		}
	}

	int sumRange(int left, int right) const
	{
		if (!left)
		{
			return prefixSum[right];
		}
		return prefixSum[right] - prefixSum[left];
	}
};