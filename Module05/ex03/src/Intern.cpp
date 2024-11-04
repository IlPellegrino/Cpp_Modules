#include "../include/Intern.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include <cctype>
#include <cstddef>
#include <iostream>

Intern::Intern() {
	std::cout << "DEFAULT Intern constructor has been called\n";
}

Intern::Intern(const Intern& i) {
	*this = i;
}

Intern&	Intern::operator=(const Intern& i) {
	if (this != &i) {}

	return *this;
}

Intern::~Intern() {
	std::cout << "Intern Destructor has been called\n";
}

Form*	Intern::makePresidentialPardonForm(std::string target) {
	return new PresidentialPardonForm(target);
}

Form*	Intern::makeRobotomyRequestForm(std::string target) {
	return new RobotomyRequestForm(target);
}

Form*	Intern::makeShrubberyCreationForm(std::string target) {
	return new ShrubberyCreationForm(target);
}

Form*	Intern::makeForm(std::string name, std::string target) {
	std::string	names[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	Form*	(Intern::*functions[3])(std::string target) = {&Intern::makePresidentialPardonForm, &Intern::makeRobotomyRequestForm, &Intern::makeShrubberyCreationForm};

	for (size_t i = 0; i <= name.size(); i++)
		name[i] = std::tolower(name[i]);

	int i;
	for (i = 0; i < 3; i++) {
		if (names[i] == name) {
			std::cout << "Intern creates " << name << std::endl;
			return (this->*functions[i])(target);
		}
	}

	std::cerr << "Form " << name << " doesn't exist. Try again\n";

	return NULL;
}