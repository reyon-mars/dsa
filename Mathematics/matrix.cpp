#include <optional>
#include <print>
#include <utility>
#include <vector>

template <typename T>
struct Matrix
{
private:
	int rows{0};
	int cols{0};
	std::vector<T> data;

	Matrix(int r, int c) : rows(r), cols(c), data(r * c, 0)
	{
	}

public:
	using Dimension = std::pair<int, int>;

	Matrix() = default;

	static std::optional<Matrix> createMatrix(int r, int c)
	{
		if (r <= 0 || c <= 0)
		{
			return std::nullopt;
		}
		return Matrix(r, c);
	}

	Dimension dimension() const
	{
		return {rows, cols};
	}

	T& operator[](int row, int col)
	{
		return data[(row * cols) + col];
	}

	const T& operator[](int row, int col) const
	{
		return data[(row * cols) + col];
	}
};