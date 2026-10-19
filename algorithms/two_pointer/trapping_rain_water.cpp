#include <vector>

int trap(const std::vector<int>& height)
{
	const int n{static_cast<int>(height.size())};

	if (n < 3)
		return 0;

	int left{0};
	int right{n - 1};
	int leftMax{0};
	int rightMax{0};
	int currHeight{0};
	long long totalWater{0};

	while (left <= right)
	{
		if (leftMax <= rightMax)
		{
			currHeight = height[left];
			leftMax = std::max(currHeight, leftMax);
			totalWater = (totalWater + (leftMax - currHeight));
			++left;
		}
		else
		{
			currHeight = height[right];
			rightMax = std::max(currHeight, rightMax);
			totalWater = (totalWater + (rightMax - currHeight));
			--right;
		}
	}
	return totalWater;
}