#include <algorithm>
#include <cstddef>
#include <utility>
#include <vector>

int carFleet(int target, const std::vector<int>& position, const std::vector<int>& speed)
{
	const std::size_t n{position.size()};

	std::vector<std::pair<int, double>> cars;
	cars.reserve(n);

	for (std::size_t i{0}; i < n; ++i)
		cars.push_back({position[i], (static_cast<double>(target - position[i]) / speed[i])});

	std::ranges::sort(cars,
					  [&](const auto& a, const auto& b)
					  {
						  return a.first > b.first;
					  });

    int fleetCount{ 0 };
    double slowestTime{ 0.0 };

    for( const auto& [position, currTime] : cars )
    {
        if( currTime > slowestTime )
        {
            fleetCount++;
            slowestTime = currTime;
        }
    }
    return fleetCount;
}