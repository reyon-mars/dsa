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

	friend std::optional<Matrix<T>> operator*(const Matrix<T>& lhs, const Matrix<T>& rhs)
	{
		if (lhs.cols != rhs.rows)
		{
			return std::nullopt;
		}
		auto result_opt = Matrix<T>::createMatrix(lhs.rows, rhs.cols);
		if (!result_opt)
		{
			return std::nullopt;
		}

		Matrix<T>& result = *result_opt;

		for (int r = 0; r < lhs.rows; ++r)
		{
			for (int c = 0; c < rhs.cols; ++c)
			{
				T sum = T();
				for (int k = 0; k < lhs.cols; ++k)
				{
					sum += lhs[r, k] * rhs[k, c];
				}
				result[r, c] = sum;
			}
		}
		return result;
	}

	friend std::optional<Matrix<T>> operator*(const std::optional<Matrix<T>>& lhs, const std::optional<Matrix<T>>& rhs)
	{
		if (!lhs || !rhs)
		{
			return std::nullopt;
		}
		return (*lhs) * (*rhs);
	}
};