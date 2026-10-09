#include <vector>
#include <unordered_set>
#include <algorithm>

int longestConsecutive( std::vector<int>& nums )
{
  std::unordered_set<int> numSet( nums.begin(), nums.end() );
  int longestStreak{0};

  for( const auto num : nums )
    {
      if( !numSet.contains( num - 1 )
      {
        int currNum { num };
        int currStreak { 1 };
        while( numSet.contains( currNum + 1 ) )
          {
            currNum++;
            currStreak++;
          }
        longestStreak = std::max( longestStreak, currStreak );
      }
    }
  return longestStreak;
}
