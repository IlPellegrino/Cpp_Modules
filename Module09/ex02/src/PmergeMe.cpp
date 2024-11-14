#include "../include/PmergeMe.hpp"
#include <algorithm>
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <exception>
#include <iterator>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

void printVec(std::vector<int> vec);
void printDeque(std::deque<int> deque);

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

const char*	PmergeMe::DuplicatesFoundExceptiond::what() const throw() {
	return "Error: duplicates not allowed\n";
}


	// -------------------- //
	//		VECTOR PART		//
	// -------------------- //


//	NOW ALL PAIRS HAVE THE GREATEST NUMBER IN THE FIRST SLOT	//
void	PmergeMe::sortInPairs(std::vector<std::pair<int, int> >& pairs)
{
	for (size_t idx = 0; idx < pairs.size(); idx++) {
		if (pairs[idx].first < pairs[idx].second) {
			std::swap(pairs[idx].first, pairs[idx].second);
		}
	}
}

void	PmergeMe::merge(std::vector<std::pair<int, int> >& pairs, int left, int mid, int right)
{
	int	firstHalf = mid - left + 1, secondHalf = right - mid;

	std::vector<std::pair<int, int> >	leftV, rightV;

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

std::vector<int>	PmergeMe::createJacobsthalSequence(size_t size)
{
	std::vector<int> jacob;
	jacob.push_back(0);
	jacob.push_back(1);

	int prev = 1, prev2 = 0, j2, j;

	for (size_t i = 2; jacob.size() < size + 1; i++) {
		j = prev;
		j2 = 2 * (prev2);
		jacob.push_back(j + j2);
		for (int sum = (j + j2) - 1; sum > prev; sum--) {
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

	for (i = 0; i < pairs.size() - 1; i++)
	{
		if (pairs[i].second == toFind)
			break;
	}

	iterator it = std::find(main.begin(), main.end(), pairs[i].first);

	return it;
}

void	PmergeMe::putInMainAndPend(std::vector<std::pair<int, int> >& pairs) {
	std::vector<int>	pend;
	if (pairs.size() == 1) {
		_mainV.push_back(pairs[0].second);
		_mainV.push_back(pairs[0].first);
		if (_oddNumber == true) {
		iterator it = std::lower_bound(_mainV.begin(), _mainV.end(), _struggler);
		_mainV.insert(it, _struggler);
		}
		return;
	}
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (!i)
			_mainV.push_back(pairs[i].second);
		_mainV.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}
	

	// BINARY SEARCH //
	std::vector<int>	jacobsthalNumbers = createJacobsthalSequence(pend.size());
	if (jacobsthalNumbers.empty()) {
		for (size_t i = 0; i < pend.size(); i++) {
			if (i == 0)
				continue;
			iterator it = std::lower_bound(_mainV.begin(), _mainV.end(), pend[i]);
			_mainV.insert(it, pend[i]);
		}
	} else {
		for (size_t i = 0; i < jacobsthalNumbers.size(); i++) {
			size_t	JacobIdx = jacobsthalNumbers[i] - 1;
			if (JacobIdx >= pend.size())
				continue;
			iterator it = std::lower_bound(_mainV.begin(), searchGreatestOf(pairs, _mainV, pend[JacobIdx]), pend[JacobIdx]);
			_mainV.insert(it, pend[JacobIdx]);
		}
	}

	// ORDER THE REMAINING NUMBER IF ODD IS TRUE //
	if (_oddNumber == true) {
		iterator it = std::lower_bound(_mainV.begin(), _mainV.end(), _struggler);
		_mainV.insert(it, _struggler);
	}
}



	// -------------------- //
	//     DEQUE PART       //
	// -------------------- //

//	NOW ALL PAIRS HAVE THE GREATEST NUMBER IN THE FIRST SLOT	//
void	PmergeMe::sortDequeInPairs(std::deque<std::pair<int, int> >& pairs)
{
	for (size_t idx = 0; idx < pairs.size(); idx++) {
		if (pairs[idx].first < pairs[idx].second) {
			std::swap(pairs[idx].first, pairs[idx].second);
		}
	}
}

std::deque<int>	PmergeMe::createDequeJacobsthalSequence(size_t size)
{
	std::deque<int> jacob;
	jacob.push_back(0);
	jacob.push_back(1);

	int prev = 1, prev2 = 0, j2, j;
	for (int i = 2; jacob.size() < size + 1; i++) {
		j = prev;
		j2 = 2 * (prev2);
		jacob.push_back(j + j2);
		for (int sum = (j + j2)- 1; sum > prev; sum--) {
			jacob.push_back(sum);
		}
		prev2 = prev;
		prev = j + j2;
	}

	// ERASE THE FIRST 3 ELEMENTS OF JACOBSTHAL NUMBERS (0, 1, 1) //
	jacob.erase(jacob.begin());
	jacob.erase(jacob.begin());
	jacob.erase(jacob.begin());

	return jacob;
}

dIt	searchGreatestOfDeque(std::deque<std::pair<int, int> >& pairs, std::deque<int>& main, const int toFind)
{
	size_t	i;

	for (i = 0; i < pairs.size() - 1; i++)
	{
		if (pairs[i].second == toFind)
			break;
	}

	dIt it = std::find(main.begin(), main.end(), pairs[i].first);

	return it;
}

void	PmergeMe::putDequeInMainAndPend(std::deque<std::pair<int, int> >& pairs)
{
	// CHECK FOR 1 PAIR ONLY //
	if (pairs.size() == 1) {
		_mainD.push_back(pairs[0].second);
		_mainD.push_back(pairs[0].first);
		if (_oddNumber == true) {
		dIt it = std::lower_bound(_mainD.begin(), _mainD.end(), _struggler);
		_mainD.insert(it, _struggler);
		}
		return;
	}

	std::deque<int>	pend;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (!i)
			_mainD.push_back(pairs[i].second);
		_mainD.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}

	// BINARY SEARCH //
	std::deque<int>	jacobsthalNumbers = createDequeJacobsthalSequence(pend.size());
	if (jacobsthalNumbers.empty()) {
		for (size_t i = 0; i < pend.size(); i++) {
			if (i == 0)
				continue;
			dIt it = std::lower_bound(_mainD.begin(), _mainD.end(), pend[i]);
			_mainD.insert(it, pend[i]);
		}
	} else {
		for (size_t i = 0; i < jacobsthalNumbers.size(); i++) {
			int	JacobIdx = jacobsthalNumbers[i] - 1;
			if ((size_t)JacobIdx >= pend.size())
				continue;
			dIt it = std::lower_bound(_mainD.begin(), searchGreatestOfDeque(pairs, _mainD, pend[JacobIdx]), pend[JacobIdx]);
			_mainD.insert(it, pend[JacobIdx]);
		}
	}

	// ORDER THE REMAINING NUMBER IF ODD IS TRUE //
	if (_oddNumber == true) {
		dIt it = std::lower_bound(_mainD.begin(), _mainD.end(), _struggler);
		_mainD.insert(it, _struggler);
	}
}

void	PmergeMe::mergeDeque(std::deque<std::pair<int, int> >& pairs, int left, int mid, int right)
{
	int	firstHalf = mid - left + 1, secondHalf = right - mid;

	std::deque<std::pair<int, int> >	leftV, rightV;

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

void	PmergeMe::recursiveDequePairSort(std::deque<std::pair<int, int> >& pairs, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		recursiveDequePairSort(pairs, left, mid);
		recursiveDequePairSort(pairs, mid + 1, right);

		mergeDeque(pairs, left, mid, right);
	}
}



	// ---------------------------------------------------------------	//
	//						START & COMMON FUNCTIONS					//
	// ---------------------------------------------------------------	//

int	PmergeMe::parseNumber(const std::string& token)
{
	if (token.empty())
		throw InvalidTokenException();

	for (int i = 0; token[i]; i++) {
		if (!std::isdigit(token[i])) {
			throw InvalidTokenException();
		}
	}
	int	number = atoi(token.c_str());
	return number;
}

void printVec(std::vector<int> vec) {
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec.at(i) << " ";
	}
	std::cout << '\n';
}

void printDeque(std::deque<int> deque) {
	for (size_t i = 0; i < deque.size(); i++) {
		std::cout << deque.at(i) << " ";
	}
	std::cout << '\n';
}

void	PmergeMe::printAll(char **av, int n, double vectorTime, double dequeTime)
{
	std::cout << "Before: ";
	for (int i = 1; av[i]; i++) {
		std::cout << av[i] << " ";
	}
	std::cout << "\n\n";
	std::cout << "After: ";
	printVec(_mainV);

	std::cout << "\nTime to process a range of " << n << " elements with std::vector -> " << vectorTime << " us\n";
	std::cout << "Time to process a range of " << n << " elements with std::deque -> " << dequeTime << " us\n";
}

bool	checkForDuplicates(char **av, int n)
{
	if (n == 1) {
		std::istringstream stream(av[1]);
		std::string word;
		std::vector<std::string> values;

		// Split by space and store in vector
		while (stream >> word) {
			if (std::find(values.begin(), values.end(), word) != values.end()) {
				return true; // Duplicate found
			}
			values.push_back(word);
		}
	} else {
		for (int i = 1; i < n; ++i) {
			for (int j = i + 1; j < n + 1; ++j) {
				if (std::string(av[i]) == std::string(av[j])) {
					return true;
				}
			}
		}
	}

	return false;
}

void	PmergeMe::start(char **av, int n)
{
	size_t i;
	for (i = 0; i < std::string(av[1]).size(); i++) {
		if (std::string(av[1]).at(i) != ' ')
			break;
	}
	if (i == std::string(av[1]).size()) {
		throw InvalidTokenException();
	}
	if (checkForDuplicates(av, n))
		throw DuplicatesFoundExceptiond();

	std::vector<std::pair<int, int> >	vPairs;
	std::deque<std::pair<int, int> >	dPairs;

	// ONE ARG ELSE MORE ARGS//
	if (n == 1) {

		if (std::string(av[1]).empty()) {
			throw InvalidTokenException();
		}
		std::vector<int>	vArr;
		std::deque<int>		dArr;

		std::stringstream	stream((std::string(av[1])));
		std::string	token;

		// COPY AV INTO CONTAINERS //
		while(stream >> token) {
			int number;

			number = parseNumber(token);
			vArr.push_back(number);
			dArr.push_back(number);
		}

		if (vArr.size() == 1 && dArr.size() == 1) {
			_mainV.push_back(vArr[0]);
			_mainD.push_back(dArr[0]);
			printAll(av, n, 0, 0);
			return;
		}

		// CREATE CONTAINERS WITH PAIRS //
		for (iterator it = vArr.begin(); it < vArr.end(); it += 2) {
			if ((it + 1) != vArr.end()) {
				vPairs.push_back(std::make_pair(*it, *(it + 1)));
			} else if (n % 2 != 0 && (it + 1) == vArr.end()) {
				_oddNumber = true;
				_struggler = *it;
				break;
			}
		}

		for (dIt it = dArr.begin(); it < dArr.end(); it += 2) {
			if ((it + 1) != dArr.end()) {
				dPairs.push_back(std::make_pair(*it, *(it + 1)));
			} else if (n % 2 != 0 && (it + 1) == dArr.end()) {
				_oddNumber = true;
				if (*it == _struggler) 
					_struggler = *it;
				break;
			}
		}
	} else if (n == 2 || n == 3) {
		int number = parseNumber(av[1]);
		int	number2 = parseNumber(av[2]);
		vPairs.push_back(std::make_pair(number, number2));
		dPairs.push_back(std::make_pair(number, number2));

		if (n == 3) {
			int temp = parseNumber(av[3]);
			_oddNumber = true;
			_struggler = temp;
		}
	} else {
		for (int i = 1; av[i]; i += 2) {
			if (av[i + 1] != NULL) {
				int number = parseNumber(av[i]);
				int	number2 = parseNumber(av[i + 1]);
				vPairs.push_back(std::make_pair(number, number2));
				dPairs.push_back(std::make_pair(number, number2));
			}
			if (n % 2 != 0 && av[i + 1] == NULL) {
				int temp = parseNumber(av[i]);
				_oddNumber = true;
				_struggler = temp;
				break;
			}
		}
	}
 
	std::clock_t	vectorStart = std::clock();
	sortInPairs(vPairs);
	recursivePairSort(vPairs, 0, vPairs.size() - 1);
	putInMainAndPend(vPairs);
	std::clock_t	vectorEnd = std::clock();

	std::clock_t	dequeStart = std::clock();
	sortDequeInPairs(dPairs);
	recursiveDequePairSort(dPairs, 0, dPairs.size() - 1);
	putDequeInMainAndPend(dPairs);
	std::clock_t	dequeEnd = std::clock();
	
	double vectorTime = static_cast<double>(vectorEnd - vectorStart) / (CLOCKS_PER_SEC / 1000);
	double	dequeTime = static_cast<double>(dequeEnd - dequeStart) / (CLOCKS_PER_SEC / 1000);

	printAll(av, n, vectorTime, dequeTime);
}