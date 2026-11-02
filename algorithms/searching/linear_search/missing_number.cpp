#include <numeric>
#include <vector>

int missingNumber(const std::vector<int>& vec)
{
	const auto n{static_cast<int>(vec.size())};
	auto sum_till_n{((n) * (n + 1)) / 2};

	return sum_till_n - std::accumulate(vec.begin(), vec.end(), 0);
}