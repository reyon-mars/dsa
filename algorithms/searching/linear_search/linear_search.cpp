#include <algorithm>
#include <cstddef>
#include <iterator>
#include <vector>

template <typename T>
int stl_search(const std::vector<T>& vec, T target)
{
	auto it{std::ranges::find(vec, target)};
	if (it != vec.end())
	{
		return static_cast<int>(std::ranges::distance(vec.begin(), it));
	}
	return -1;
}

template <typename T>
int search(const std::vector<T>& vec, T target)
{
	if (vec.empty())
		return -1;
	const std::size_t n{vec.size()};

	for (std::size_t i{0}; i < n; ++i)
	{
		if (vec[i] == target)
			return static_cast<int>(i);
	}
	return -1;
}
