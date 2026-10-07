#include <cstddef>
#include <functional>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

std::vector<int> kMostFreq(std::vector<int>& vec, size_t k)
{
	const size_t n = vec.size();
	if (k > n)
		return {-1};

	std::unordered_map<int, int> count;
	count.reserve(n);

	for (const auto num : vec)
		count[num]++;

	using Pair = std::pair<int, int>;
	std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> min_heap;

	for (const auto& [num, freq] : count)
	{
		min_heap.push({freq, num});
		if (min_heap.size() > k)
			min_heap.pop();
	}

	std::vector<int> result;
	result.reserve(k);
	while (!min_heap.empty())
	{
		result.push_back(min_heap.top().second);
		min_heap.pop();
	}
	return result;
}