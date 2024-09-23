#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl		harl;

	if (argc != 2) {
		std::cout << "\nWrong number of arguments!\nLevels: [DEBUG] [INFO] [WARNING] [ERROR]\n\n";
		return 1;
	}
	harl.complain(argv[1]);
}