#include <cstddef>
#include <cstdint>
#include <print>

int32_t reverse_bits_iterative(int num)
{
	uint32_t u_num{static_cast<uint32_t>(num)};
	uint32_t result{0};

	for (size_t i = 0; i < 32; ++i)
	{
		auto lsb{(u_num >> i) & 1};
		result = (result << 1) | lsb;
	}
	return result;
}

