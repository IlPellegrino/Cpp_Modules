#include <iostream>

int	main()
{
	std::string s = "HI THIS IS BRAIN";
	std::string *stringPTR = &s;
	std::string& stringREF = s;

	std::cout << "The address of s is: " << &s << std::endl;
	std::cout << "The address of PTR is: " << &stringPTR << std::endl;
	std::cout << "The address of REF is: " << &stringREF << std::endl;

	std::cout << "The value of s is: " << s << std::endl;
	std::cout << "The value of PTR is: " << stringPTR << std::endl;
	std::cout << "The value of REF is: " << stringREF << std::endl;
}