#include <algorithm>
#include <vector>

constexpr inline bool canFinish(const std::vector<int>& piles, const int h, const int speed)
{
	long long hours{0};
	for (const auto pile : piles)
	{
		hours += (pile / speed) + (pile % speed != 0);
	}
	return hours <= h;
}

int minEatingSpeed(const std::vector<int>& piles, int h)
{
	if (piles.empty())
		return 0;

	int left{1};
	int right{*std::ranges::max_element(piles)};

	while (left < right)
	{
		int mid{left + (right - left) / 2};
		if (canFinish(piles, h, mid))
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return left;
}