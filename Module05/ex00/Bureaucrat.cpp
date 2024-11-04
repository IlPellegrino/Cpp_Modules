#include "Bureaucrat.hpp"
#include <iostream>
#include <ostream>
#include <string>

Bureaucrat::Bureaucrat() {
	std::cout << "DEFAULT constructor has been called\n";
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
	return "\nException: Grade is too high! Must be between 1 and 150.\n";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return "\nException: Grade is too low! Must be between 1 and 150.\n";
}

	// SETTERS //

void	Bureaucrat::setGrade(int grade) {
	checkGrade(grade);
	_grade = grade;
}

	// GETTERS //

std::string	Bureaucrat::getName() {
	return _name;
}

int	Bureaucrat::getGrade() {
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

std::ostream&	operator<<(std::ostream& os, Bureaucrat& b) {
	os << b.getName() << ", Bureaucrat grade " << b.getGrade() << std::endl;
	
	return os;
}