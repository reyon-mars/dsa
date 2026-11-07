#include <vector>

std::vector<int> asteroidCollision(const std::vector<int>& asteroids)
{
	std::vector<int> stack{};
	stack.reserve(asteroids.size());

	for (const auto asteroid : asteroids)
	{
		bool destroyed{false};
		while (!destroyed && !stack.empty() && stack.back() > 0 && asteroid < 0)
		{
			if (stack.back() < -asteroid)
			{
				stack.pop_back();
			}
			else if (stack.back() == -asteroid)
			{
				stack.pop_back();
				destroyed = true;
			}
			else
			{
				destroyed = true;
			}
		}
		if (!destroyed)
		{
			stack.push_back(asteroid);
		}
	}
	return stack;
}