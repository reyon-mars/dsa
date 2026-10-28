#include <cstddef>
#include <vector>

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