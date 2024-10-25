#include "../include/PmergeMe.hpp"
#include <algorithm>
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iterator>
#include <sstream>
#include <utility>
#include <vector>

// CONSTRUCTORS

PmergeMe::PmergeMe() : _struggler(0), _oddNumber(false) {}

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

void printVec(std::vector<int> vec) {
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec.at(i) << " ";
	}
	std::cout << '\n';
}

void	PmergeMe::printAll(char **av, double vectorTime)
{
	std::cout << "Before: ";
	for (int i = 1; av[i]; i++) {
		std::cout << av[i] << " ";
	}
	std::cout << "\n";
	std::cout << "After: ";
	printVec(_mainV);
	std::cout << "Vector time: " << vectorTime << " us\n";
}

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

void	PmergeMe::sortInPairs(std::vector<std::pair<int, int> >& pairs) //all pairs have now the biggest number in the first element of the pair
{
	for (size_t idx = 0; idx < pairs.size(); idx++) {
		if (pairs[idx].first < pairs[idx].second) {
			std::swap(pairs[idx].first, pairs[idx].second);
		}
	}
}

void	PmergeMe::merge(std::vector<std::pair<int, int> >& pairs, int left, int mid, int right)
{
	int	firstHalf = mid - left + 1;
	int	secondHalf = right - mid;

	std::vector<std::pair<int, int> >	leftV;
	std::vector<std::pair<int, int> >	rightV;

	for (int i = 0; i < firstHalf; i++)
		leftV.push_back(pairs[left + i]);
	for (int j = 0; j < secondHalf; j++)
		rightV.push_back(pairs[mid + 1 + j]);

	int i = 0, j = 0, l = left;

	while (i < firstHalf && j < secondHalf)
	{
		if (leftV[i].first <= rightV[j].first)
		{
			pairs[l] = leftV[i];
			i++;
		} else {
			pairs[l] = rightV[j];
			j++;
		}
		l++;
	}

	while (i < firstHalf)
	{
		pairs[l] = leftV[i];
		l++;
		i++;
	}
	while (j < secondHalf)
	{
		pairs[l] = rightV[j];
		l++;
		j++;
	}
}

std::vector<int>	PmergeMe::createJacobsthalSequence(int size)
{
	std::vector<int> jacob;
	jacob.push_back(0);
	jacob.push_back(1);
	int j;
	int j2;
	int prev = 1, prev2 = 0;

	for (int i = 2; i < size + 1; i++) {
		j = prev;
		j2 = 2 * (prev2);
		jacob.push_back(j + j2);
		for (int sum = (j + j2)- 1; sum > prev; sum--) {
			jacob.push_back(sum);
		}
		prev2 = prev;
		prev = j + j2;
	}

	// erase the first 3 jacobsthal numbers //
	jacob.erase(jacob.begin());
	jacob.erase(jacob.begin());
	jacob.erase(jacob.begin());

	return jacob;
}

iterator	searchGreatestOf(std::vector<std::pair<int, int> >& pairs, std::vector<int>& main, const int toFind)
{
	size_t	i;

	for (i = 0; i < pairs.size() -1 ; i++)
	{
		if (pairs[i].second == toFind)
			break;
	}

	iterator it = std::find(main.begin(), main.end(), pairs[i].first);

	return it;
}

void	PmergeMe::putInMainAndPend(std::vector<std::pair<int, int> >& pairs)
{
	std::vector<int>	pend;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (!i)
			_mainV.push_back(pairs[i].second);
		_mainV.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}

	// BINARY SEARCH //
	std::vector<int>	jacobsthalNumbers = createJacobsthalSequence(pend.size());
	for (size_t i = 0; i < pend.size() + 1; i++)
	{
		int	JacobIdx = jacobsthalNumbers[i] - 1;
		if ((size_t)JacobIdx >= pend.size())
			continue;
		iterator it = std::lower_bound(_mainV.begin(), searchGreatestOf(pairs, _mainV, pend[JacobIdx]), pend[JacobIdx]);
		_mainV.insert(it, pend[JacobIdx]);
	}

	// ORDER THE REMAINING NUMBER IF ODD IS TRUE //
	if (_oddNumber == true) {
		iterator it = std::lower_bound(_mainV.begin(), _mainV.end(), _struggler);
		_mainV.insert(it, _struggler);
	}
}

void	PmergeMe::recursivePairSort(std::vector<std::pair<int, int> >& pairs, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		recursivePairSort(pairs, left, mid);
		recursivePairSort(pairs, mid + 1, right);

		merge(pairs, left, mid, right);
	}
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
				_oddNumber = true;
				_struggler = *it;
			}
		}

	} else //more args
	{
		for (int i = 1; av[i]; i += 2)
		{
			if (av[i + 1] != NULL) {
				int number = parseNumber(av[i]);
				int	number2 = parseNumber(av[i + 1]);
				pairs.push_back(std::make_pair(number, number2));
			}
			if (n % 2 != 0 && av[i + 1] == NULL) {
				int temp = parseNumber(av[i]);
				_oddNumber = true;
				_struggler = temp;
				break;
			}
		}
	} 
	std::clock_t vectorStart = std::clock();
	sortInPairs(pairs);
	recursivePairSort(pairs, 0, pairs.size() - 1);
	putInMainAndPend(pairs);
	std::clock_t	vectorEnd = std::clock();
	double vectorTime = static_cast<double>(vectorEnd - vectorStart) / (CLOCKS_PER_SEC / 1000);
	printAll(av, vectorTime);
}

	// -------------------- //
	//     DEQUE PART       //


