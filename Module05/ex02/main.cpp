#include "include/Bureaucrat.hpp"
#include "include/AForm.hpp"
#include "include/PresidentialPardonForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include <iostream>
#include <ostream>

int	main()
{
	try {

		Bureaucrat		lawyer("Gianni", 78);
		Bureaucrat		president("Ciuschi", 170);
		Bureaucrat		bartender("Arturo", 52);

		ShrubberyCreationForm	tree("HOME");
		RobotomyRequestForm		robot("Rob");
		PresidentialPardonForm	Pres("John");

		tree.beSigned(president);

		president.signForm(tree);

		president.executeForm(tree);

	} catch (AForm::GradeTooHighException& high) {
		std::cerr << high.what();
	} catch (AForm::GradeTooLowException& low) {
		std::cerr << low.what();
	} catch (AForm::FormNotSignedException& sign) {
		std::cerr << sign.what();
	} catch (Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what();
	} catch (Bureaucrat::GradeTooLowException& i) {
		std::cerr << i.what();
	}

}