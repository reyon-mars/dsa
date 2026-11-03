#include <numeric>
#include <vector>

int missingNumber(const std::vector<int>& vec)
{
	const auto n{static_cast<int>(vec.size())};
	auto sum_till_n{((n) * (n + 1)) / 2};

	return sum_till_n - std::accumulate(vec.begin(), vec.end(), 0);
}

int missing_number(const std::vector<int>& vec)
{
	const auto n{static_cast<int>(vec.size())};
	int answer{n};

	for (int i{0}; i < n; ++i)
	{
		answer ^= i;
		answer ^= vec[i];
	}
	return answer;
}