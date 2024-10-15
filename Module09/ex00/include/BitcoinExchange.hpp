#pragma once

#include <ctime>
#include <exception>
#include <map>
#include <iostream>
#include <string>

typedef std::map<time_t, float>::iterator iterator;
typedef std::map<time_t, float>::const_iterator const_iterator;

class	BitcoinExchange {
	private:
		float						value;
		time_t						date;
		std::map<time_t, float>		DataBaseBtc;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& btc);
		BitcoinExchange&	operator=(const BitcoinExchange& btc);
		~BitcoinExchange();

		class	InvalidFormat : public std::exception {
			public:
				const char * what() const throw();
		};

		void	setValue(const std::string& valueToSet);

		float	getResult(const time_t& closestDate, float rate);

		time_t	stringToDate(const std::string& date);
		time_t	findClosestDate(const time_t& targetTime);
		bool	isValidValue(const std::string& value);
};