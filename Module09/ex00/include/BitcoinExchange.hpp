#pragma once

#include <exception>
#include <map>
#include <iostream>
#include <string>

typedef std::map<std::string, float>::iterator iterator;

class	BitcoinExchange {
	private:
		float						value;
		std::string					date;
		std::map<std::string, float>	DataBaseBtc;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& btc);
		BitcoinExchange&	operator=(const BitcoinExchange& btc);
		~BitcoinExchange();

		class	InvalidFormat : std::exception {
			const char * what() const throw();
		};

		void	setDate(std::string dateToSet);
		void	setValue(std::string valueToSet);

		bool	isValidDate(const std::string& date);
		bool	isValidValue(const std::string& value);
};