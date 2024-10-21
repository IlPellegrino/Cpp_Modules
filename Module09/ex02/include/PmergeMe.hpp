#pragma once

#include <exception>
#include <iostream>
#include <utility>
#include <vector>

typedef std::vector<int>::iterator	iterator; 

class	PmergeMe {
	private:
		int _struggler;
		
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& p);
		PmergeMe& operator=(const PmergeMe& p);
		~PmergeMe();

		class	InvalidTokenException : public std::exception {
			public:
				const char * what() const throw();
		};

		// class	InvalidException : public std::exception {
		// 	public:
		// 		const char * what() const throw();
		// };

		void	startPairing(char **av, int n);
		int		parseNumber(const std::string& token);
		void	mergeInPairs(std::vector<std::pair<int, int>>& pairs);
		
};