#pragma once

#include <exception>
#include <map>
#include <iostream>

class	BitcoinExchange {
	private:
		
		std::map<std::string, int> DataBaseBtc;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& btc);
		BitcoinExchange&	operator=(const BitcoinExchange& btc);
		~BitcoinExchange();

		class	InvalidFormat : std::exception {
			const char * what() const throw();
		};

		bool	isValidDate(const std::string& date);
};