#include <vector>

bool hasEvenNumOfDigits(int num)
{
	auto digitCount{0};
	while (num)
	{
		digitCount++;
		num /= 10;
	}
	return !(digitCount & 1);
}

int findNumbers(const std::vector<int>& nums)
{
	auto count{0};
	for (const auto num : nums)
	{
		if (hasEvenNumOfDigits(num))
			count++;
	}
	return count;
}

int find_numbers(const std::vector<int>& nums)
{
	auto count{0};
	for (const auto num : nums)
	{
		if ((num >= 10 && num <= 99) || (num >= 1000 && num <= 9999) || (num >= 100000 && num <= 999999))
		{
			count++;
		}
	}
	return count;
}