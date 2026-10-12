#include <bit>
#include <climits>
#include <cstddef>

int unsetKthBit(int n, int k)
{
	if (n == 0)
		return n;

	const int total_bits{(static_cast<int>(std::bit_width(UINT_MAX)) - __builtin_clz(n))};

	if (total_bits < k)
		return n;

	const int right_idx{total_bits - k};
	return n & ~(1U << right_idx);
}