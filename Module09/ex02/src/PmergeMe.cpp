#include "../include/PmergeMe.hpp"
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <exception>
#include <iterator>
#include <sstream>
#include <utility>
#include <vector>

// CONSTRUCTORS

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& p) { (void)p; }

PmergeMe&	PmergeMe::operator=(const PmergeMe& p) {
	(void)p;
	return *this;
}

PmergeMe::~PmergeMe() {}

const char*	PmergeMe::InvalidTokenException::what() const throw() {
	return "Error: invalid token\n";
}

// VECTOR ALGORITHM

int	PmergeMe::parseNumber(const std::string& token)
{
	for (int i = 0; token[i]; i++) {
		if (!std::isdigit(token[i])) {
			throw InvalidTokenException();
		}
	}
	int	number = atoi(token.c_str());
	if (token.empty())
		throw InvalidTokenException();
	return number;
}

void	PmergeMe::startPairing(char **av, int n)
{
	std::vector<std::pair<int, int> >	pairs;

	if (n == 1) //one arg
	{
		std::vector<int>	arr;

		std::string numbers = std::string(av[1]);

		std::stringstream	stream(numbers);

		std::string	token;

		while(stream >> token) // copy av into a vector
		{
			int number;

			try {
				number = parseNumber(token);
			} catch (std::exception& e) { (void)e; }
			arr.push_back(number);
		}

		for (iterator it = arr.begin(); it < arr.end(); it += 2) // create the container with pairs
		{
			if ((it + 1) != arr.end()) {
				pairs.push_back(std::make_pair(*it, *(it + 1)));
			} else if (n % 2 != 0 && (it + 1) == arr.end()) {
				_struggler = *it;
			}
		}

	} else //more args
	{
		for (int i = 1; av[i]; i += 2) {
			if (av[i + 1] != NULL) {
				pairs.push_back(std::make_pair(atoi(av[i]), atoi(av[i + 1])));
			}
			if (n % 2 != 0 && av[i + 1] == NULL) {
				_struggler = atoi(av[i]);
			}
		}
	} 
	mergeInPairs(pairs);
	
}