#include "Replace.hpp"

Replace::Replace() {}

Replace::~Replace() {}

void	Replace::replaceFile(char **argv) {
	std::string		originalFname(argv[1]);
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];

	std::ifstream	iFile(originalFname.c_str());
	if (!iFile.is_open()) {
		std::cerr << "Error opening file for reading\n";
		return;
	}

	std::string	newFname;
	int			pos = originalFname.find_last_of(".");
	int			tmp = originalFname.length() - pos;
	originalFname.resize(tmp);
	newFname = originalFname + ".replace";

	std::ofstream	oFile(newFname.c_str());
	if (!oFile.is_open()) {
		std::cerr << "Error opening file for writing\n";
		return;
	}

	std::string	line;
	int	start;
	while (getline(iFile, line)) {
		while ((start = line.find(s1)) != -1) {
			line.erase(start, s1.length());
			line.insert(start, s2);
		}
		oFile << line << std::endl;
	}


	// std::ostringstream oss;
	// oss << file.rdbuf();
	// std::string wholeFile = oss.str();
	// file.close();

	iFile.close();
	oFile.close();

	std::cout << "The content has been copied and replaced to: " << newFname << std::endl;
}
