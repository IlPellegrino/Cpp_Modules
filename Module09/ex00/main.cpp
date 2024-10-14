#include <fstream>
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Error: only one argument accepted\n";
		std::cerr << "Usage: " << argv[0] << "<filename>\n";
		return 1;
	}
	
	std::ifstream	iFile(argv[1]);

	if (!iFile.is_open()) {
		std::cerr << "Error: could not open the file\n";
		return 1;
	}
	
}