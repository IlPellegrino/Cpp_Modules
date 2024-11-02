#include "Replace.hpp"
#include <cstddef>
#include <cstdio>

Replace::Replace() {}

Replace::~Replace() {}

void	Replace::replaceFile(char **argv) {
	std::string		originalFname(argv[1]);
	std::string		s1 = std::string(argv[2]);
	std::string		s2 = argv[3];

	if (s1 == s2 || s1.empty() || s2.empty()) {
		std::cerr << "args cannot be empty\n";
		return;
	}

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
	int	startLine = 0;
	int size = 0;

	for (int i = 0; i < iFile.end; i++) {
		getline(iFile, line);
		size++;
	}
	while (getline(iFile, line)) {
		while ((start = line.find(s1)) != -1) {
			line.erase(start, s1.size());
			line.insert(start, s2);
		}
		startLine++;
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
