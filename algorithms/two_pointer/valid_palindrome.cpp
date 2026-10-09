#include <cctype>
#include <string>

bool isPalindrome(const std::string& str)
{
	int left{0};
	int right{static_cast<int>(str.size() - 1)};

	while (left < right)
	{
		while (left < right && !std::isalnum(static_cast<unsigned char>(str[left])))
			left++;
		while (left < right && !std::isalnum(static_cast<unsigned char>(str[right])))
			right--;
		if (std::tolower(static_cast<unsigned char>(str[left])) != std::tolower(static_cast<unsigned char>(str[right])))
			return false;
		left++;
		right--;
	}

	return true;
}