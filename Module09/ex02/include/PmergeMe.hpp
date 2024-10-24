#pragma once

#include <deque>
#include <exception>
#include <iostream>
#include <utility>
#include <vector>

typedef std::vector<int>::iterator					iterator;
typedef std::vector<std::pair<int, int> >::iterator	pair_iterator;

class	PmergeMe {
	private:
		std::vector<int>	_mainV;
		std::deque<int>		_mainD;
		int 				_struggler;
		
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

		std::vector<int>	createJacobsthalSequence(int size);
		int		parseNumber(const std::string& token);
		void	startPairing(char **av, int n);
		void	putInMainAndPend(std::vector<std::pair<int, int> >& pairs);
		void	merge(std::vector<std::pair<int, int> >& pairs, int left, int mid, int right);
		void	sortInPairs(std::vector<std::pair<int, int> >& pairs);
		void	recursivePairSort(std::vector<std::pair<int, int> >& pairs, int left, int right);
};