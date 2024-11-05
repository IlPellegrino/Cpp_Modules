#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <ostream>
#include <string>

Bureaucrat::Bureaucrat() : _name("Default"), _grade(28) {
	std::cout << "DEFAULT constructor has been called\n";
	setGrade(_grade);
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
	std::cout << "Constructor has been called\n";
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& b) {
	(std::string)_name = b._name;
	_grade = b._grade;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& b) {
	(std::string)this->_name = b._name;
	this->_grade = b._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor has been called\n";
}

void	Bureaucrat::checkGrade(int grade) {
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	} else if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
}

const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return "\nException: Grade is too high! Must be between 1 and 150.\n\n";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return "\nException: Grade is too low! Must be between 1 and 150.\n\n";
}

	// SETTERS //

void	Bureaucrat::setGrade(int grade) {
	checkGrade(grade);
	_grade = grade;
}

	// GETTERS //

std::string	Bureaucrat::getName() const {
	return _name;
}

int	Bureaucrat::getGrade() const {
	return _grade;
}

void	Bureaucrat::upGrade(int amount) {
	int tmp = _grade;
	tmp -= amount;
	checkGrade(tmp);
	_grade -= amount;
}

void	Bureaucrat::downGrade(int amount) {
	int tmp = _grade;
	tmp += amount;
	checkGrade(tmp);
	_grade += amount;
}

void	Bureaucrat::signForm(const Form& f) {
	if (f.getIsSigned() == true) {
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	} else {
		std::cout << this->getName() << " couldn't sign " << f.getName() << " because the grade is not higher or equivalent\n";
	}
}

std::ostream&	operator<<(std::ostream& os, Bureaucrat& b) {
	os << b.getName() << ", Bureaucrat grade " << b.getGrade() << std::endl;
	
	return os;
}
