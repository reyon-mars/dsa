#include <concepts>
#include <vector>

template <typename T>
  requires std::equality_comparable<T>
int count( const std::vector<T>& arr, const T& target ) 
{
  int freq { 0 };

  for ( const auto &item : arr) 
  {
    if (item == target) 
	{
      freq++;
    }
  }
  return freq;
};