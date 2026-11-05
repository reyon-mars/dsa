#include <vector>

std::vector<int> getConcatenation(const std::vector<int>& vec)
{
	const int n{static_cast<int>(vec.size())};
	std::vector<int> result(vec);
	result.append_range(vec);
	return result;
}
