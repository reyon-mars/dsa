#include <vector>

int removeElement(std::vector<int>& vec, int val)
{
	if (vec.empty())
		return 0;

	const int n{static_cast<int>(vec.size())};
	int write_idx{0};

	for (int i{0}; i < n; ++i)
	{
		if (vec[i] != val)
		{
			vec[write_idx] = vec[i];
			write_idx++;
		}
	}
	return write_idx++;
}