#include <string>
#include <string_view>

constexpr inline bool is_palindrome(std::string_view s, int left, int right)
{
	while (left < right)
	{
		if (s[left] != s[right])
		{
			return false;
		}
		left++;
		right--;
	}
	return true;
}

bool validPalindrome(const std::string& s)
{
	int left{0};
	int right{static_cast<int>(s.size()) - 1};

	while (left < right)
	{
		if (s[left] != s[right])
		{
			return is_palindrome(s, left + 1, right) || is_palindrome(s, left, right - 1);
		}
		left++;
		right--;
	}
	return true;
}