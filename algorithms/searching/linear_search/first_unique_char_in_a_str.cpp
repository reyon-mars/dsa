#include <array>
#include <string>

int firstUniqueChar(const std::string& str)
{
	std::array<size_t, 26> count{};

	unsigned char currChar{};
	for (const unsigned char ch : str)
	{
		count[ch - 'a']++;
	}

	for (size_t i{0}; i < str.size(); ++i)
	{
		if (count[static_cast<unsigned char>(str[i]) - 'a'] == 1)
		{
			return i;
		}
	}
	return -1;
}