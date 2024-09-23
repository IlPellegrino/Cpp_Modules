#include "../include/Intern.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include <cstddef>
#include <iostream>

Intern::Intern() {
	std::cout << "DEFAULT Intern constructor has been called\n";
}

Intern::Intern(const Intern& i) {
	*this = i;
}

Intern&	Intern::operator=(const Intern& i) {
	if (this != &i) {

	}

	return *this;
}

Intern::~Intern() {
	std::cout << "Intern Destructor has been called\n";
}

Form*	Intern::makeForm(std::string name, std::string target) {
	std::string	names[] = {"presidential pardon", "Presidential Pardon", "robotomy request", "Robotomy Request", "shrubbery creation", "Shrubbery Creation"};

	int i = 0;
	for (; i < 6; i++) {
		if (names[i] == name)
			break;
	}

	switch (i) {
		case 0:
		case 1:
			PresidentialPardonForm *form;
			form = new PresidentialPardonForm(target);
			std::cout << "Intern creates " << name << std::endl;
			return form;
		
		case 2:
		case 3:
			RobotomyRequestForm *form_1;
			form_1 = new RobotomyRequestForm(target);
			std::cout << "Intern creates " << name << std::endl;
			return form_1;
		
		case 4:
		case 5:
			ShrubberyCreationForm *form_2;
			form_2 = new ShrubberyCreationForm(target);
			std::cout << "Intern creates " << name << std::endl;
			return form_2;

		default:
			std::cerr << "Form doesn't exist. Try again\n";
			return NULL;
	}
}