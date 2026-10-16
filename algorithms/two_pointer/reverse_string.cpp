#include <utility>
#include <vector>

void reverseString(std::vector<char>& str)
{
	int left{0};
	int right{static_cast<int>(str.size()) - 1};

	while (left < right)
	{
		std::swap(str[left], str[right]);
		left++;
		right--;
	}
}