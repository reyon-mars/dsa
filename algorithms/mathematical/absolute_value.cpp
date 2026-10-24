#include <print>
int absolute_value(int val)
{
	return val < 0 ? val * -1 : val;
}

int main()
{
	int my_num{};
	std::println("{}", absolute_value(my_num));
	return 0;
}