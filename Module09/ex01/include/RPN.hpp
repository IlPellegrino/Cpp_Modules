#pragma once

#include <exception>
#include <iostream>
#include <stack>

class	RPN {
	private:
		std::stack<int>	_calculator;
		int				_result;

	public:
		RPN(std::string input);
		RPN(const RPN& r);
		RPN&	operator=(const RPN& r);
		~RPN();

		class	InvalidTokenException : public std::exception {
			public:
				const char * what() const throw();
		};

		bool	parseInput(std::string input);
		void	splitToStack(std::string& toSplit, char toSkip, std::stack<int>& cal);
		bool	countNumbers(std::string input);
		int		doOperation();
		void	printResult();
		bool	isoperand(char c);

};