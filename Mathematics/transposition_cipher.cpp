#include <algorithm>
#include <cstddef>
#include <string>
#include <utility>
#include <vector>

void encrypt(std::string& str)
{
	auto n = str.size();
	if (n <= 2)
	{
		return;
	}

	// Use a Stack to track all the sub string range with size greater than 2
	std::vector<std::pair<size_t, size_t>> stack;
	stack.reserve(n >> 1);

	// Start with the entire string
	stack.push_back({0, n});

	// Run the loop until all the sub string ranges have be resolved
	while (!stack.empty())
	{
		// Get the range of the sub string
		auto [start, end] = stack.back();
		stack.pop_back();

		// Calculate the length of the sub string
		// If less then or equal to 2 Continue.
		size_t len = end - start;
		if (len <= 2)
		{
			continue;
		}

		// Half the length
		// Add Half of the length to the start to find the middle of the range
		size_t k = len >> 1;
		size_t mid = start + k;

		// Reverse each half independently
		std::reverse(str.begin() + start, str.begin() + mid);
		std::reverse(str.begin() + mid, str.begin() + end);

		// Add the two section of the current string
		// Seperate from the half
		stack.push_back({start, mid});
		stack.push_back({mid, end});
	}
	return;
}