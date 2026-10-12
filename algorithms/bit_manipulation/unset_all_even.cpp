#include <cstdint>

int unsetEven(int n)
{
	constexpr uint32_t ODD_MASK{0xAAAAAAAA};
	return ODD_MASK & n;
}