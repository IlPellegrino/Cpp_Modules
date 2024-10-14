#include "../include/BitcoinExchange.hpp"
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

BitcoinExchange::BitcoinExchange() {
	std::ifstream	data("data.csv");
	
	if (!data) {
		std::cerr << "Error: could not open file\n";
		return;
	}

	std::string	line;
	iterator	dbIt;

	while (std::getline(data, line)) {
		size_t pos = line.find(",");
		if (pos == std::string::npos) {
			throw InvalidFormat();
		}
		setDate(line.substr(0, pos));
		setValue(line.substr(pos + 1, line.size()));
		this->DataBaseBtc[date] = value;
	}

	// for (dbIt = DataBaseBtc.begin(); dbIt != DataBaseBtc.end(); dbIt++) {
	// 	std::cout << "key " << dbIt->first << " value: " << dbIt->second << std::endl;
	// }

	std::cout << "Constructor called\n";
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::setDate(std::string dateToSet) {
	if (isValidDate(dateToSet) == false) {
		return;
	}
	date = dateToSet;
}

void	BitcoinExchange::setValue(std::string valueToSet) {
	value = std::atof(valueToSet.c_str());
}

const char*	BitcoinExchange::InvalidFormat::what() const throw() {
	return "Invalid Format\nUsage for date: YYYY-MM-DD\nValue must be between 0 and 1000\n";
}

bool	BitcoinExchange::isValidDate(const std::string& date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
		return false;
	}

	struct	tm tm = {};
	
	if (strptime(date.c_str(), "%Y-%m-%d", &tm) == NULL) {
		std::cerr << "Date format not valid\n";
		return false;
	}

	return true;
}

bool	BitcoinExchange::isValidValue(const std::string& value) {
	float tmp = std::atof(value.c_str());
	if (tmp < 0) {
		std::cerr << "Error: value is negative\n";
		return false;
	} else if (tmp > 1000) {
		std::cerr << "Error: value is too big\n";
		return false;
	}
	return true;
}