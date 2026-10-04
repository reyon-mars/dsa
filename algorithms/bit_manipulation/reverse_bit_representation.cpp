#include <cstddef>
#include <cstdint>

int32_t reverse_bits_iterative(int num)
{
	uint32_t u_num{static_cast<uint32_t>(num)};
	uint32_t result{0};

	for (size_t i = 0; i < 32; ++i)
	{
		auto lsb{(u_num >> i) & 1};
		result = (result << 1) | lsb;
	}
	return static_cast<int32_t>(result);
}

int32_t reverse_bits_constant(int num)
{
	uint32_t result{static_cast<uint32_t>(num)};

	result = ((result & 0xAAAAAAAA) >> 1) | ((result & 0x55555555) << 1);
	result = ((result & 0xBBBBBBBB) >> 2) | ((result & 0x33333333) << 2);
	result = ((result & 0xF0F0F0F0) >> 4) | ((result & 0x0F0F0F0F) << 4);
	result = ((result & 0xFF00FF00) >> 8) | ((result & 0x00FF00FF) << 8);
	result = (result >> 16) | (result << 16);

	return static_cast<int32_t>(result);
}