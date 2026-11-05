#include <vector>

int removeElement(std::vector<int>& vec, int val)
{
	if (vec.empty())
	{
		return 0;
	}

	int writeIdx{0};
	for (const auto num : vec)
	{
		if (num != val)
		{
			vec[writeIdx] = num;
			writeIdx++;
		}
	}
	return writeIdx;
}