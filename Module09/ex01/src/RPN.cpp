#include "../include/RPN.hpp"
#include <cmath>

RPN::RPN() {}

RPN::RPN(const RPN& r) { (void)r; }

RPN&	RPN::operator=(const RPN& r) {
	(void)r;
	return *this;
}

RPN::~RPN() {}

const char*	RPN::InvalidTokenException::what() const throw() {
	return "Error: invalid token\n";
}

const char* RPN::InvalidExpressionException::what() const throw() {
	return "Error: invalid expression\n";
}

float	RPN::parseNumber(const std::string& token)
{
	char	*end;

	float number = std::strtof(token.c_str(), &end);

	if (end == token.c_str() || !end || *end != '\0') {
		throw RPN::InvalidTokenException();
	}
	return number;
}

float	RPN::doOperation(float n1, float n2, const char op)
{
	if (op == '+') {
		return n1 + n2;
	} else if (op == '-') {
		return n1 - n2;
	} else if (op == '*') {
		return n1 * n2;
	} else if (op == '/') {
		return n1 / n2;
	} else {
		throw InvalidExpressionException();
	}
}


float	RPN::splitToStack(const std::string& input) {
	if (input.empty()) {
		throw InvalidTokenException();
	}

	std::stack<float>	operands;

	std::stringstream	stream(input);

	std::string			token;

	while (stream >> token)
	{
		bool	isNumber = false;
		float number = -1;
		try {
			number = parseNumber(token);
			isNumber = true;
		} catch (std::exception& e) {(void)e;}

		if (token.size() == 1 && isoperator(token[0])) {
			if (operands.size() < 2) {
				throw InvalidExpressionException();
			}
			float n1 = operands.top();
			operands.pop();

			float n2 = operands.top();
			operands.pop();

			float result = RPN::doOperation(n1, n2, token[0]);
			operands.push(result);
		}
		else if (isNumber) {
			if (number < 0 || number > 9) {
				throw InvalidTokenException();
			}
			operands.push(number);
		}
		else {
			throw InvalidTokenException();
		}
	}
	if (operands.size() != 1) {
		throw InvalidExpressionException();
	}

	return operands.top();
}

bool	RPN::isoperator(const char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*') {
		return true;
	}
	return false;
}
