#include <cstddef>
#include <vector>

std::vector<int> plusOne(std::vector<int>& vec)
{
	if (vec.back() < 9)
	{
		auto& lastElem{vec.back()};
		++lastElem;
		return vec;
	}

	const size_t lastIdx{vec.size() - 1};
	for (int i = lastIdx; i >= 0; ++i)
	{
		if (vec[i] == 9)
		{
			vec[i] = 0;
		}
		else
		{
			vec[i]++;
			return vec;
		}
	}
	vec.insert(vec.begin(), 1);
	return vec;
}