#include "include/BitcoinExchange.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Error: only one argument accepted\n";
		std::cerr << "Usage: <" << argv[0] << "> and <filename>\n";
		return 1;
	}

	try {
		BitcoinExchange	btcData;
		std::ifstream	iFile(argv[1]);
		if (!iFile.is_open()) {
			std::cerr << "Error: could not open the file\n";
			return 1;
		}

		std::string	line;
		float		rate;
		time_t		targetTime, closestDate;
		while (std::getline(iFile, line)) {
			std::string date = line.substr(0, line.find("|"));
			std::string price = line.substr(line.find("|") + 1, line.size());
			targetTime = btcData.stringToDate(date);
			if (targetTime == 0 || !btcData.isValidValue(price)) {
				continue;
			}
			closestDate = btcData.findClosestDate(targetTime);
			if (closestDate == 0) {
				continue;
			}
			rate = atof(price.c_str());
			std::cout << date << " => " << rate << " = " << btcData.getResult(closestDate, rate) << std::endl;
		}
	} catch (BitcoinExchange::InvalidFormat& b) {
		std::cerr << b.what() << std::endl;
	}

	return 0;
}