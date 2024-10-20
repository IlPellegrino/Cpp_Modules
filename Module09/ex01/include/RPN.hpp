#pragma once

#include <exception>
#include <cctype>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

class	RPN {
	private:
		static float	doOperation(float n1, float n2, const char op);

		static float	parseNumber(const std::string& token);

		static bool		isoperator(const char c);

	public:
		RPN();
		RPN(const RPN& r);
		RPN&	operator=(const RPN& r);
		~RPN();


		static float	splitToStack(const std::string& input);
	
	public:
	
		class	InvalidTokenException : public std::exception {
			public:
				const char * what() const throw();
		};

		class InvalidExpressionException : std::exception {
			public:
				const char * what() const throw();
		};

};