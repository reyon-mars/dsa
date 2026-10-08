#include <unordered_set>
#include <vector>
#include <algorithm>

int longestConsecutive( std::vector<int>& nums )
{
  std::unordered_set<int> numSet( nums.begin(), nums.end() );
  int longestStreak { 0 };

  for( const auto num: nums ){
    if( set.contains( num - 1) ) {
      int currentNum = num;
      int currentStreak {1};
    }
  }
}
