#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>

class	Span {
	private:
		unsigned int	_maxN;
		std::vector<int>	numbers;

	public:
		Span(unsigned int N);
		Span(const Span& s);
		Span&	operator=(const Span& s);
		~Span();

		unsigned int	getMaxN();

		void	addNumber(int n);
		int		shortestSpan(); // return shortest gap
		int		longestSpan(); // return longest gap

};

#endif