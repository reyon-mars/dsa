#include <vector>

std::vector<float> average_of_subarrays(const std::vector<int>& arr, int k)
{
	const int n = static_cast<int>( arr.size() );

	if (k > n )
	{
		return {};
	}

	std::vector<float> result;
	result.reserve(arr.size() - k + 1);

	int window_sum { 0 };
	for (int i = 0; i < k; i++)
	{
		window_sum += arr[i];
	}

	result.push_back(static_cast<float>(window_sum) / static_cast<float>(k));
	
	for (int i = k; i < n; i++)
	{
		window_sum += arr[i] - arr[i - k];
		result.push_back(static_cast<float>(window_sum) / static_cast<float>(k));
	}
	return result;
}
