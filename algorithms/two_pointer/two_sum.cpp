#include <vector>

bool twoSum(std::vector<int>& vec, int target)
{
	int left{0};
	int right{static_cast<int>(vec.size()) - 1};

	while (left < right)
	{
		int sum{vec[left] + vec[right]};
		if (sum == target)
			return true;
		else if (sum < target)
			left++;
		else
			right--;
	}
	return false;
}