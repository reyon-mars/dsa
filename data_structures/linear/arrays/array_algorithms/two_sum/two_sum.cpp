#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

bool two_sum_2_pointer(std::vector<int>& arr, int target, bool is_sorted = false)
{
	if (arr.size() < 2 || arr.empty())
	{
		return false;
	}
	size_t left(0), right(arr.size() - 1);
	if (!is_sorted)
	{
		std::sort(arr.begin(), arr.end());
	}

	while (left < right)
	{
		if ((arr[left] + arr[right]) < target)
		{
			left++;
		}
		else if (target < (arr[left] + arr[right]))
		{
			right--;
		}
		else
		{
			return true;
		}
	}
	return false;
}

bool twoSum( std::vector<int>& vec, int target )
{
	std::unordered_set<int> seen;
	seen.reserve( vec.size() );
	
	for( const auto num : vec )
	{
		if( seen.contains( target - num ) ) 
			return true;

		seen.insert( num );
	}
	return false;
}