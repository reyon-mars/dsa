#include "matrix.hpp"
#include <print>

int main()
{
	auto matA = Matrix<int>::createMatrix({{1, 2, 3}, {4, 5, 6}});

	auto matB = Matrix<int>::createMatrix({{1, 2}, {3, 4}, {5, 6}});

	if (matA && matB)
	{
		auto matC = matA * matB;

		std::println("{}", *matC);
	}
}