#include "include/Intern.hpp"
#include "include/Form.hpp"
#include "include/PresidentialPardonForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include <iostream>
int	main()
{
	Bureaucrat	lawyer("gino", 25);
	Intern someRandomIntern;
	Form* rrf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	std::cout << lawyer.getGrade();

	rrf->beSigned(lawyer);

	rrf->execute(lawyer);


	delete rrf;
}