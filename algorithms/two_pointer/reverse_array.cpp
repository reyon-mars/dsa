#include <vector>

void reverse(std::vector<int>& vec)
{
	int left{0};
	int right{static_cast<int>(vec.size() - 1)};

	while (left < right)
	{
		std::swap(vec[left], vec[right]);
		left++;
		right--;
	}
}