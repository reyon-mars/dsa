#include <string>
#include <vector>

std::string Encode(const std::vector<std::string>& strs)
{
	std::string encodedStr{""};
	for (const auto& str : strs)
	{
		encodedStr += std::to_string(str.size()) + "#" + str;
	}
	return encodedStr;
}

std::vector<std::string> Decode(const std::string& encodedStr)
{
	std::vector<std::string> result;

	const int n{static_cast<int>(encodedStr.length())};

	for (int i{0}; i < n; ++i)
	{
		int j{i};
		while (encodedStr[j] != '#')
			j++;

		int length{std::stoi(encodedStr.substr(i, (j - i)))};
		result.push_back(encodedStr.substr((j + 1), length));
		i = j + length + 1;
	}
	return result;
}