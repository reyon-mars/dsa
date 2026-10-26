#include <vector>

bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target)
{
	if (matrix.empty())
		return false;

	const auto m{static_cast<int>(matrix.size())};
	const auto n{static_cast<int>(matrix.front().size())};

	int left{0};
	int right{m * n - 1};

	while (left <= right)
	{
		int mid{left + (right - left) / 2};
		int row{mid / n};
		int col{mid % n};

		if (matrix[row][col] == target)
		{
			return true;
		}
		else if (matrix[row][col] < target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return false;
}