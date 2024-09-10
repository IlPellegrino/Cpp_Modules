#include "include/Bureaucrat.hpp"
#include "include/AForm.hpp"
#include "include/PresidentialPardonForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include <iostream>
#include <ostream>

int	main()
{
	Bureaucrat		lawyer("Gianni", 78);
	Bureaucrat		president("Ciuschi", 24);
	Bureaucrat		bartender("Arturo", 52);
	
	
	ShrubberyCreationForm	tree("HOME");
	RobotomyRequestForm		robot("Rob");
	PresidentialPardonForm	Pres("John");

	tree.beSigned(president);
	
	president.signForm(tree);

	president.executeForm(tree);

}