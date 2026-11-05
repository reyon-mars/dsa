#include <vector>

std::vector<int> getConcatenation(const std::vector<int>& vec)
{
	const int n{static_cast<int>(vec.size())};
	std::vector<int> result(vec);
	result.append_range(vec);
	return result;
}

std::vector<int> get_Concatenation(std::vector<int>& vec)
{
	const int n{static_cast<int>(vec.size())};
	vec.resize(n * 2);

	for (int i{0}; i < n; ++i)
	{
		vec[n + i] = vec[i];
	}
	return vec;
}