#include "include/RPN.hpp"

int	main(int argc, char **av)
{
	if (argc != 2) {
		std::cerr << "Error: wrong number of arguments\n";
		return 1;
	}

	try {
		std::string	input = std::string(av[1]);
		RPN	rpn(input);
		if (rpn.doOperation() == -1) {
			return 1;
		}
		rpn.printResult();
	} catch (RPN::InvalidTokenException& c) {
		std::cerr << c.what();
	}


}