#include <vector>

std::vector<int> sortedSquares(const std::vector<int>& nums)
{
	const int n{static_cast<int>(nums.size())};
	std::vector<int> result(n);
	int left{0};
	int right{n - 1};
	int writeIdx{n - 1};

	while (left <= right)
	{
		int leftSquare{nums[left] * nums[left]};
		int rightSquare{nums[right] * nums[right]};
		if (leftSquare > rightSquare)
		{
			result[writeIdx] = leftSquare;
			left++;
		}
		else
		{
			result[writeIdx] = rightSquare;
			right--;
		}
		writeIdx--;
	}
	return result;
}