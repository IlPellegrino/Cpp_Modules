#pragma once

# include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
# include <string>


class	Intern {
	public:
		Intern();
		Intern(const Intern& i);
		Intern&	operator=(const Intern& i);
		~Intern();
	
	private:
		Form*	makePresidentialPardonForm(std::string target);
		Form*	makeRobotomyRequestForm(std::string target);
		Form*	makeShrubberyCreationForm(std::string target);

	public:
		Form*	makeForm(std::string name, std::string target);
};


