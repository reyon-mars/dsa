#include <string>
#include <vector>

std::string longestCommonPrefix(const std::vector<std::string>& strs)
{
	if (strs.empty())
	{
		return "";
	}
	const int n{static_cast<int>(strs.size())};
	std::string match{strs.front()};

	for (int i{0}; i < n; ++i)
	{
		std::string currWord{strs[i]};
		int j{0};
		while (j < currWord.length() && j < match.length() && currWord[j] == match[j])
		{
			j++;
		}
		match.erase(j);
		if (match.empty())
		{
			return "";
		}
	}
	return match;
}