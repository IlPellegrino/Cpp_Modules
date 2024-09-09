#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <ostream>

int	main()
{
	Bureaucrat	n("Pino", 250);
	std::cout << n << std::endl;

	Bureaucrat	s("Gianni", 50);
	std::cout << std::endl << s << std::endl;

	Form		first("Scienze", 30, 20);
	std::cout << std::endl << first << std::endl;

	Form		second("Maths", 50, 80);
	std::cout << std::endl << second << std::endl;

	second.beSigned(s); // grade should be ok
	std:: cout << "bene\n";

	first.beSigned(s); // grade should be not ok
	std:: cout << "bene\n";


	second.beSigned(s); // should work
	std:: cout << "bene\n";


	std::cout << second << std::endl;

	std::cout << "Hello from " << n.getName() << ", I am graduated and I suck!\nThis is because my grade is " << n.getGrade() << std::endl;

	std::cout << std::endl << s.getName() << " is trying to change his grade!";
	s.upGrade(50);

	std::cout << "\n" << s.getName() << " is trying to change his grade!";
	s.downGrade(200);
}