#include "Bureaucrat.hpp"
#include <iostream>

int	main()
{
	Bureaucrat	n("Pino", 250);
	Bureaucrat	s("Gianni", 50);

	std::cout << n;
	std::cout << s;

	std::cout << "Hello from " << n.getName() << ", I am graduated and I suck!\nThis is because my grade is " << n.getGrade() << std::endl;

	std::cout << std::endl << s.getName() << " is trying to change his grade!";
	s.upGrade(50);

	std::cout << "\n" << s.getName() << " is trying to change his grade!";
	s.downGrade(200);
}