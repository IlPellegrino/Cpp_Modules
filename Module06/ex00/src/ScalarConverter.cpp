#include "../include/ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <sstream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

void	printDouble(double d)
{
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	if (!c) {
		std::cout << "Char: ciao" << c << std::endl;
	} else {
		std::cout << "Char: " << c << std::endl;
	}
	std::cout << "Int: " << i << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "Double: " << std::fixed << std::setprecision(1) << d << std::endl;
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
	std::cout << "Float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "Double: " << std::fixed << std::setprecision(1) << d << std::endl;
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

void	printImpossible()
{
	std::cout << "Char: impossible" << std::endl;
	std::cout << "Int: impossible" << std::endl;
	std::cout << "Float: impossible" << std::endl;
	std::cout << "Double: impossible" << std::endl;
}

int	displayable(char toSee)
{
	if ((toSee < '0' && toSee > '9')
		|| (toSee != '-' && toSee != '+')
		|| (toSee < 'a' && toSee > 'z')
		|| (toSee < 'A' && toSee > 'Z'))
		return 0;
	return 1;
}

void	ScalarConverter::convert(std::string toConvert)
{
	//check if char
	if (toConvert.size() == 1) {
		if ((toConvert[0] >= 'a' && toConvert[0] <= 'z')
			|| (toConvert[0] >= 'A' && toConvert[0] <= 'Z')) {
			printChar(toConvert[0]);
			return;
		}
		else if (toConvert[0] >= '0' && toConvert[0] <= '9') {
			char *c;
			int num = std::strtol(toConvert.c_str(), &c, 10);
			if (c == toConvert.c_str() || *c != '\0') {
				printImpossible();
				return;
			}
			printInt(num);
			return;
		}
	}

	// if (!displayable(toConvert[0])) {
	// 	std::cout << "ciao";
	// 	printImpossible();
	// 	return;
	// }
	
	char *test;
	double k = std::strtod(toConvert.c_str(), &test);
	if (test == toConvert.c_str() || *test != '\0') {
		printImpossible();
		return;
	} else {
		printDouble(k);
		return;
	}

	test = NULL;
	float j = std::strtof(toConvert.c_str(), &test);
	if (test == toConvert.c_str() || *test != '\0') {
		printImpossible();
		return;
	} else {
		printFloat(j);
		return;
	}

}
