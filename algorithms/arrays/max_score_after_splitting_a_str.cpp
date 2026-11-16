#include <algorithm>
#include <string>

int maxScore(const std::string& str)
{
	const int n{static_cast<int>(str.size())};

	int leftScore{0};
	int rightScore{static_cast<int>(std::ranges::count(str, '1'))};
	int maxScore{0};

	for (int i{0}; i < (n - 1); ++i)
	{
		str[i] == '0' ? ++leftScore : --rightScore;
		maxScore = std::max(maxScore, (leftScore + rightScore));
	}
	return maxScore;
}