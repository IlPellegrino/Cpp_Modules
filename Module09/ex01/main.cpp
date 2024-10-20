#include "include/RPN.hpp"

int	main(int argc, char **av)
{
	if (argc != 2) {
		std::cerr << "Error: wrong number of arguments\n";
		return 1;
	}

	try {
		float result = RPN::splitToStack(av[1]);
		std::cout << "Result: " << result << std::endl;
	} catch (RPN::InvalidTokenException& c) {
		std::cerr << c.what();
	} catch (RPN::InvalidExpressionException& e) {
		std::cerr << e.what();
	}

	return 0;
}