#pragma once

#include <string>

class	ScalarConverter {
	private:
		ScalarConverter();

	public:
		~ScalarConverter();

		static void	convert(std::string toConvert);
};
