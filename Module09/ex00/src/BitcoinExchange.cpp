#include "../include/BitcoinExchange.hpp"
#include <fstream>
#include <limits>
#include <string>

BitcoinExchange::BitcoinExchange() {
	std::ifstream	data("../data.csv");
	
	if (!data) {
		std::cerr << "Error: could not open file\n";
		return;
	}

	std::string	date;
	int			value;

	while (data >> date >> value) {
		if (!isValidDate(date)) {
			throw InvalidFormat();
		}
		this->DataBaseBtc[date] = value;
	}


}

const char*	BitcoinExchange::InvalidFormat::what() const throw() {
	return "Invalid Format\nUsage for date: YYYY-MM-DD\nValue must be between 0 and 1000\n";
}

bool	isValidDate(const std::string& date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
		return false;
	}

	int	year = std::stoi(date.substr(0, 4));
	int	month = std::stoi(date.substr(5, 2));
	int	day = std::stoi(date.substr(8, 2));

	if ((year > 2025 || year < 0) || (month > 12 || month < 1) || (day < 1 || day > 31)) {
		return false;
	}
	return true;
}