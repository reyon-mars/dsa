#include <vector>

int largestRectangleArea(const std::vector<int>& heights)
{
	const int n{static_cast<int>(heights.size())};

	int maxArea{0};
	std::vector<int> stack;
	stack.reserve(n);

	for (int i{0}; i <= n; ++i)
	{
		while (!stack.empty() && (i == n || heights[stack.back()] >= heights[i]))
		{
			int height{heights[stack.back()]};
			stack.pop_back();
			int width{stack.empty() ? i : i - stack.back() - 1};
			maxArea = std::max(maxArea, height * width);
		}
		if (i < n)
		{
			stack.push_back(i);
		}
	}
	return maxArea;
}