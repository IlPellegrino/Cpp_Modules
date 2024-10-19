#include "../include/RPN.hpp"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <sstream>
#include <stack>
#include <string>

RPN::RPN(std::string input) : _result(0) {
	splitToStack(input, ' ', _calculator);

}

const char*	RPN::InvalidTokenException::what() const throw() {
	return "Error: invalid token\n";
}

void	RPN::splitToStack(std::string& toSplit, char toSkip, std::stack<int>& cal) {
	std::istringstream	ss(toSplit);
	std::string			token;

	while (std::getline(ss, token, toSkip)) {
		if (token.size() == 1 && std::isdigit(token[0])) {
			cal.push(std::atoi(token.c_str()));
		} else if (token.size() == 1 && isoperand(token[0])) {
			continue;
		} else {
			throw InvalidTokenException();
		}
	}
}

bool	RPN::isoperand(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*') {
		return true;
	}
	return false;
}