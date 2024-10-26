#pragma once

#include <cstddef>
#include <deque>
#include <exception>
#include <iostream>
#include <utility>
#include <vector>

typedef std::deque<int>::iterator					dIt;
typedef std::deque<std::pair<int, int> >::iterator	dPairIt;

typedef std::vector<int>::iterator					iterator;
typedef std::vector<std::pair<int, int> >::iterator	pair_iterator;

class	PmergeMe {
	private:
		std::vector<int>	_mainV;
		std::deque<int>		_mainD;
		int 				_struggler;
		bool				_oddNumber;
		
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& p);
		PmergeMe& operator=(const PmergeMe& p);
		~PmergeMe();

		class	InvalidTokenException : public std::exception {
			public:
				const char * what() const throw();
		};

		class	DuplicatesFoundExceptiond : public std::exception {
			public:
				const char * what() const throw();
		};

		void	start(char **av, int n);
		int		parseNumber(const std::string& token);
		void	printAll(char **av, int n, double vectorTime, double dequeTime); // ADD ALSO THE DEQUE TIME //

		//	------------ VECTOR -------------	//

		std::vector<int>	createJacobsthalSequence(size_t size);
		void	sortInPairs(std::vector<std::pair<int, int> >& pairs);
		void	recursivePairSort(std::vector<std::pair<int, int> >& pairs, int left, int right);
		void	merge(std::vector<std::pair<int, int> >& pairs, int left, int mid, int right);
		void	putInMainAndPend(std::vector<std::pair<int, int> >& pairs);

		//	------------ DEQUE --------------	//

		std::deque<int>	createDequeJacobsthalSequence(size_t size);
		void	sortDequeInPairs(std::deque<std::pair<int, int> >& pairs);
		void	recursiveDequePairSort(std::deque<std::pair<int, int> >& pairs, int left, int right);
		void	mergeDeque(std::deque<std::pair<int, int> >& pairs, int left, int mid, int right);
		void	putDequeInMainAndPend(std::deque<std::pair<int, int> >& pairs);
};