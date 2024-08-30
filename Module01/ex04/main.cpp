#include "Replace.hpp"

int	main(int argc, char **argv)
{
	Replace	rep;

	if (argc != 4) {
		std::cerr << "Wrong number of arguments\nUsage: [FILE] | [TO_FIND] | [TO_REPLACE]\n";
		return 1;
	}

	rep.replaceFile(argv);

	return 0;
}
