#include "../include/BitcoinExchange.hpp"
#include <algorithm>
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

	while (std::getline(data, line)) {
		size_t pos = line.find(",");
		if (pos == std::string::npos) {
			throw InvalidFormat();
		}
		date = stringToDate(line.substr(0, pos));
		setValue(line.substr(pos + 1, line.size()));
		this->DataBaseBtc[date] = value;
	}
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::setValue(const std::string& valueToSet) {
	value = std::atof(valueToSet.c_str());
}

float	BitcoinExchange::getResult(const time_t& closestDate, float rate) {
	return DataBaseBtc[closestDate] * rate;
}

const char*	BitcoinExchange::InvalidFormat::what() const throw() {
	return "Invalid Format\nUsage for date: YYYY-MM-DD\nValue must be between 0 and 1000\n";
}

time_t	BitcoinExchange::findClosestDate(const time_t& targetTime) {

	iterator dbIt = DataBaseBtc.lower_bound(targetTime);

	if (dbIt == DataBaseBtc.end()) {
		std::cerr << "Error: date not reached, yet :)\n";
		return 0;
	} else if (dbIt == DataBaseBtc.begin()) {
		std::cerr << "Error: date not found\n";
		return 0;
	}

	if (dbIt->first != targetTime) {
		dbIt--;
	}
	time_t	closestDate = dbIt->first;

	return closestDate;
}

time_t	BitcoinExchange::stringToDate(const std::string& date) {

	struct	tm tm = {};
	if (strptime(date.c_str(), "%Y-%m-%d", &tm) == NULL) {
		std::cerr << "Error: date format not valid => " << date << std::endl;
		return 0;
	}

	return mktime(&tm);
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