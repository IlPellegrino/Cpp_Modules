#include "../include/Span.hpp"
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <exception>
#include <limits>
#include <stdexcept>

Span::Span(unsigned int N) : _maxN(N) {}

Span::Span(const Span& s) : _maxN(s._maxN) {
	if (this != &s) {
		*this = s;
	}
}

Span&	Span::operator=(const Span& s) {
	this->_maxN = s._maxN;

	return *this;
}

Span::~Span() {
	_maxN = 0;
}

unsigned int	Span::getMaxN() {
	return _maxN;
}

void	Span::addNumber(int n)
{
	if (numbers.size() > _maxN) {
		throw std::overflow_error("Cannot add number.\nSpan is full\n");
	}
	numbers.push_back(n);
	std::cout << "Number " << n << " has been added to the list\n";
}

void	Span::addMoreNumbers(int numbers)
{
	if (numbers <= 0) {
		throw std::logic_error("Cannot add this quantity of numbers\n");
	}
	for (int i = 0; i < numbers; i++) {
		addNumber(rand());
	}
}

int	Span::shortestSpan()
{
	if (numbers.size() < 2) {
		throw std::logic_error("Not enough numbers in Span, add more numbers\n");
	}

	std::sort(numbers.begin(), numbers.end());

	int	shortestSpan = numbers[1] - numbers[0];

	return shortestSpan;
}

int	Span::longestSpan() {
	if (numbers.size() < 2) {
		throw std::logic_error("Not enough numbers in Span, add more numbers\n");
	}
	int max = *std::max_element(numbers.begin(), numbers.end());
	int	min = *std::min_element(numbers.begin(), numbers.end());

	int	longest = max - min;

	return longest;
}

