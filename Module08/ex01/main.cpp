#include "include/Span.hpp"

int	main()
{
	Span sp = Span(100000);

	sp.addNumber(3);
	sp.addNumber(240924);
	sp.addNumber(647);
	sp.addNumber(434);
	sp.addNumber(23);
	sp.addNumber(200000);

	int	shortest = sp.shortestSpan();
	int longest = sp.longestSpan();

	std::cout << "The shortest span is " << shortest << std::endl;

	std::cout << "The longest span is " << longest << std::endl;
}