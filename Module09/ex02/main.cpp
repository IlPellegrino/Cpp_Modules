#include "include/PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac < 2) {
		std::cerr << "Error: too few arguments\nUsage: <executable> and <numbers to sort>\n";
		return 1;
	}

	PmergeMe	algo;

	try {
		algo.start(av, ac - 1);
	} catch (std::exception& e) {
		std::cerr << e.what();
	}

	return 0;
}
