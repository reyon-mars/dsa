#include <format>
#include <optional>
#include <utility>
#include <vector>

template <typename T>
struct Matrix
{
public:
	using Dimension = std::pair<int, int>;

private:
	int rows{0};
	int cols{0};
	std::vector<T> data;

	Matrix(int r, int c) : rows(r), cols(c), data(r * c, T())
	{
	}

public:
	Matrix() = default;

	static std::optional<Matrix<T>> createMatrix(std::initializer_list<std::initializer_list<T>> il)
	{
		if (il.size() == 0 || il.begin().size() == 0)
		{
			return std::nullopt;
		}
		int row_count = il.size();
		int col_count = il.begin().size();

		for (const auto& row : il)
		{
			if (row.size() != col_count)
			{
				return std::nullopt;
			}
		}
		Matrix<T> mat(row_count, col_count);

		int row_offset = 0;
		for (const auto& row : il)
		{
			auto dest_it = mat.data.begin() + row_offset;
			std::ranges::copy(row, dest_it);

			row_offset += col_count;
		}
		return mat;
	}

	static std::optional<Matrix<T>> createMatrix(int r, int c)
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

template <typename T>
struct std::formatter<Matrix<T>>
{
	std::formatter<T> underlying_formatter;
	constexpr auto parse(std::format_parse_context& ctx)
	{
		return underlying_formatter.parse(ctx);
	}
	auto format(const Matrix<T>& mat, std::format_context& ctx) const
	{
		auto [rows, cols] = mat.dimension();
		auto out = ctx.out();

		for (int r = 0; r < rows; ++r)
		{
			for (int c = 0; c < cols; ++c)
			{
				out = underlying_formatter.format(mat[r, c], ctx);
				out = std::format_to(out, " ");
			}
			if (r < (rows - 1))
			{
				out = std::format_to(out, "\n");
			}
		}
		return out;
	}
};