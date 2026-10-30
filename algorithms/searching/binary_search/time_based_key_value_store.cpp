#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class TimeMap
{
public:
	using TimeStamp = int;

private:
	struct Entry
	{
		std::vector<TimeStamp> timeStamp{};
		std::vector<std::string> value{};
	};

	std::unordered_map<std::string, Entry> tm;

public:
    
    TimeMap() = default;

	void set(const std::string& key, std::string value, TimeStamp timestamp)
	{
		auto& keySlot{tm[key]};
		keySlot.timeStamp.emplace_back(timestamp);
		keySlot.value.emplace_back(std::move(value));
	}

    std::string get( const std::string& key, TimeStamp timestamp )
    {
        auto it{ tm.find(key)};
        if( it == tm.end() ){ return "";}

        const auto& history{ it->second};
        

    }
};