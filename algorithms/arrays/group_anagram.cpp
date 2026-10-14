#include <algorithm>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& strs)
{
	if (strs.empty())
		return {};

	std::unordered_map<std::string, std::vector<std::string>> group;
	group.reserve(strs.size());

	std::string key;

	for (const auto& str : strs)
	{
		key = str;
		std::ranges::sort(key);
		group[key].push_back(str);
	}

	std::vector<std::vector<std::string>> result;
	result.reserve(group.size());

	for (auto& [key, strGroup] : group)
	{
		result.push_back(std::move(strGroup));
	}
	return result;
}