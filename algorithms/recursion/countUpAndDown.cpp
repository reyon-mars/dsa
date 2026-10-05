#include <print>

void countUpAndDown(int number)
{
	std::print(" {} ", number);
	if (number == 0)
	{
		std::println("Reached the base case. ");
		return;
	}
	countUpAndDown(number - 1);
	std::println(" {} Returning", number);
	return;
}

int main()
{
	countUpAndDown(10);
	return 0;
}