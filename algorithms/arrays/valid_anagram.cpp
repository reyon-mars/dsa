#include <array>
#include <cctype>
#include <cstddef>
#include <string>

inline std::size_t positionOf(const char ch)
{
	return static_cast<size_t>(std::tolower(static_cast<unsigned char>(ch)) - 'a');
}

bool isAnagram(const std::string& s, const std::string& t)
{
	if (s.size() != t.size())
		return false;

	const std::size_t n{s.size()};
	std::array<int, 26> match{0};

	for (std::size_t idx{0}; idx < n; ++idx)
	{
		match[positionOf(s[idx])]++;
		match[positionOf(t[idx])]--;
	}
	for (const auto count : match)
	{
		if (count)
			return false;
	}
	return true;
}