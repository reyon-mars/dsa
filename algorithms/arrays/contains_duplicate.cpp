#include <unordered_map>
#include <vector>

template <typename T>
bool contains_duplicate(std::vector<T>& vec)
{
	std::unordered_map<T, bool> seen;
	for (const auto elem : vec)
	{
		if (seen.contains(elem))
		{
			return true;
		}
		seen[elem] = true;
	}
	return false;
}