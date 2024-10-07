#include "include/Span.hpp"
#include <exception>

int	main()
{
	Span sp = Span(100);

	try {
		sp.addMoreNumbers(20);
	} catch (std::exception& ex) {
		std::cout << "Exception: " << ex.what();
	}
	try {
		std::cout << "\nshortest span: "<< sp.shortestSpan() << std::endl;
		std::cout << "\nlongest span: "<< sp.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what();
	}
}