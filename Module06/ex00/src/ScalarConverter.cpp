#include "../include/ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <sstream>
#include <string>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

void	printDouble(double d)
{
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	if (!c) {
		std::cout << "Char: impossible" << c << std::endl;
	} else {
		std::cout << "Char: " << c << std::endl;
	}
	// if ()
	std::cout << "Int: " << i << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(3) << f << "f" << std::endl;
	std::cout << "Double: " << std::fixed << std::setprecision(3) << d << std::endl;
}

void	printFloat(float f)
{
	char c = static_cast<char>(f);
	int	i = static_cast<int>(f);
	double d = static_cast<double>(f);

	if (!c) {
		std::cout << "Char: impossible" << c << std::endl;
	} else {
		std::cout << "Char: " << c << std::endl;
	}
	std::cout << "Int: " << i << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(3) << f << "f" << std::endl;
	std::cout << "Double: " << std::fixed << std::setprecision(3) << d << std::endl;
}

void	printChar(char c)
{
	int	i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	std::cout << "Char: " << c << std::endl;
	std::cout << "Int: " << i << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "Double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void	printInt(int num)
{
	float f = static_cast<float>(num);
	double d = static_cast<double>(num);

	std::cout << "Char: Non displayable\n";
	std::cout << "Int: " << num << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "Double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

bool	isDisplayable(std::string toConvert)
{
	size_t	toConvertLength = toConvert.length();
	bool	dotPresent = false;

	// For empty string
	if (toConvertLength == 0)
		return false;

	for (int i = 0; toConvert[i]; i++)
	{
		char	strPos = toConvert[i];

		// + or - only in the first position
		if (i == 0 && (strPos == '+' || strPos == '-'))
			continue;

		if (strPos == '.')
		{
			// it can continue only if the '.' is surrounded by digits
			if (!dotPresent && (isdigit(toConvert[i - 1])) && isdigit(toConvert[i + 1]))
			{
				dotPresent = true;
				continue;
			}
			else {
				return false;
			}
		}
		if (strPos == 'f')
		{
			if ((i != (int)toConvertLength && !isdigit(toConvert[i - 1])) || toConvertLength == 1)
				return false;

			continue;
		}
		if (!isdigit(strPos))
		{
			return false;
		}
	}
	return true;
}

void	printResult(std::string toChar, std::string toInt, std::string toFloat, std::string toDouble)
{
	std::cout << "Char: " << toChar << std::endl;
	std::cout << "Int: " << toInt << std::endl;
	std::cout << "Float: " << toFloat << std::endl;
	std::cout << "Double: " << toDouble << std::endl;
}

void	ScalarConverter::convert(std::string toConvert)
{
	int		convertedInt;
	float	convertedFloat;
	double	convertedDouble;

	if (toConvert == "nan" || toConvert == "nanf")
	{
		printResult("impossible", "Impossible", "nanf", "nan");
		return;
	}
	if (toConvert == "-inff" || toConvert == "+inff")
	{
		printResult("impossible", "Impossible", toConvert, toConvert.substr(0, 4));
		return;
	}
	if (toConvert == "-inf" || toConvert == "+inf")
	{
		printResult("impossible", "Impossible", toConvert + "f", toConvert);
		return;
	}

	if (toConvert.length() == 1 && !isdigit(toConvert[0]))
	{
		// CHAR CASE
		if (toConvert[0] >= 32 && toConvert[0] <= 127) {
			printChar(toConvert[0]);
			return;
		}
	}

	if (!isDisplayable(toConvert)) {
		std::cerr << "Invalid input\n";
		return;
	}

	if (toConvert.length() > 1 && toConvert[toConvert.length()] == 'f') {
		// FLOAT CASE
		std::stringstream toFloat(toConvert);
		if (!(toFloat >> convertedFloat)) {
			std::cerr << "Input [" << toConvert << "] could not be parsed, or there is an overflow\n";
			return;
		}
		printFloat(convertedFloat);
	}
	else if (toConvert.find('.') != std::string::npos) {
		// DOUBLE CASE
		std::stringstream toDouble(toConvert);
		if (!(toDouble >> convertedDouble)) {
			std::cerr << "Input [" << toConvert << "] could not be parsed, or there is an overflow\n";
			return;
		}
		printDouble(convertedDouble);
	}
	else {
		// INTEGER CASE
		std::stringstream toInt(toConvert);
		if (!(toInt >> convertedInt)) {
			std::cerr << "Input [" << toConvert << "] could not be parsed, or there is an overflow\n";
			return;
		}
		printInt(convertedInt);
	}
}
