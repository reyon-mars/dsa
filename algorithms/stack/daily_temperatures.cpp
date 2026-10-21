#include <vector>

std::vector<int> dailyTemperatures(const std::vector<int>& temperatures)
{
	const int n{static_cast<int>(temperatures.size())};

	std::vector<int> result(n, 0);
	std::vector<int> stack;
	stack.reserve(n);

	for (auto currDay(n - 1); currDay >= 0; currDay--)
	{
		while (!stack.empty() && temperatures[currDay] >= temperatures[stack.back()])
			stack.pop_back();

		if (!stack.empty())
		{
			const int futureDay{stack.back()};
			result[currDay] = futureDay - currDay;
		}
		stack.push_back(currDay);
	}
	return result;
}