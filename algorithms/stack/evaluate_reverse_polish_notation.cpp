#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

constexpr inline bool isOperator(const std::string& op)
{
	return op == "/" || op == "*" || op == "+" || op == "-";
}

constexpr inline std::int64_t compute(const char op, std::int64_t left, std::int64_t right)
{
	switch (op)
	{
	case '/':
		return left / right;
	case '*':
		return left * right;
	case '+':
		return left + right;
	case '-':
		return left - right;
	}
	return 0;
}

int evalRPN(const std::vector<std::string>& tokens)
{
	std::vector<std::int64_t> stack;
	stack.reserve(tokens.size());

	for (const std::string& token : tokens)
	{
		if (isOperator(token))
		{
			if (stack.size() < 2)
				throw std::invalid_argument("Invalid RPN expression.");

			int64_t right{stack.back()};
			stack.pop_back();

			int64_t left{stack.back()};
			stack.pop_back();

			stack.push_back(compute(token.front(), left, right));
		}
		else
		{
			stack.push_back(std::stoll(token));
		}
	}
	if (stack.size() != 1)
		throw std::invalid_argument("Invalid RPN expression.");

	return stack.back();
}