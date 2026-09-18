#include <unordered_map>
#include <vector>

int max_fruits(const std::vector<int>& arr)
{
	const int n = static_cast<int>( arr.size() );

	int fruit_max(0);
	std::unordered_map<int, int> fruit_freq;

	for (int right(0), left(0); right < n; right++)
	{
		fruit_freq[arr[right]]++;
		while (fruit_freq.size() > 2)
		{
			if (--fruit_freq[arr[left]] == 0)
			{
				fruit_freq.erase(arr[left]);
			}
			left++;
		}
		fruit_max = right - left + 1;
	}
	return fruit_max;
}
