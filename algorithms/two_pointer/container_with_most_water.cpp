#include <algorithm>
#include <vector>
int maxArea(const std::vector<int>& height)
{
	int left{0};
	int right{static_cast<int>(height.size()) - 1};
	int max_area{0};

	while (left < right)
	{
		int h_left{height[left]};
		int h_right{height[right]};

		int curr_area = (right - left) * std::min(h_left, h_right);
		max_area = std::max(curr_area, max_area);

		if (h_left < h_right)
			while (left < right && height[left] <= h_left)
				left++;
		else
			while (left < right && height[right] <= h_right)
				right--;
	}
	return max_area;
}