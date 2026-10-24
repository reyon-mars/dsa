#include <algorithm>
#include <array>
#include <string>

int longest_non_repeating_substr(const std::string& str)
{
	if (str.empty())
		return 0;

	std::array<int, 128> seen_at;
	seen_at.fill(-1);

	int left(0), right(0), max_len(0);

	while (right < str.size())
	{
		const char curr_char = str[right];

		if (seen_at[curr_char] >= 0)
		{
			left = std::max(left, seen_at[curr_char] + 1);
		}
		seen_at[curr_char] = right;
		max_len = std::max(max_len, right - left + 1);
		right++;
	}
	return max_len;
}

int lengthOfLongestSubstring(const std::string& str)
{
	const int n{static_cast<int>(str.size())};
	if (n <= 1)
		return n;

	std::array<int, 128> seenAt;
	seenAt.fill(-1);

	int maxLen{0};
	int substrStart{0};

	for (int i{0}; i < n; ++i)
	{
		const auto currChar{str[i]};

		if (seenAt[currChar] != -1 && seenAt[currChar] >= substrStart)
		{
			substrStart = seenAt[currChar] + 1;
		}
		seenAt[currChar] = i;
		maxLen = std::max(maxLen, (i - substrStart + 1));
	}
	return maxLen;
}