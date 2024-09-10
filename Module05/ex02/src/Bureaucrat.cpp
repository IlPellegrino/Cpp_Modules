#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
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
	return "Grade is too high! Must be between 1 and 150.\n";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low! Must be between 1 and 150.\n";
}

	// SETTERS //

void	Bureaucrat::setGrade(int grade) {
	try {
		checkGrade(grade);
		_grade = grade;
	} catch (const Bureaucrat::GradeTooHighException & e) {
		std::cerr << "\n\nException: " << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException & i) {
		std::cerr << "\n\nException: " << i.what() << std::endl;
	}
}

	// GETTERS //

std::string	Bureaucrat::getName() const {
	return _name;
}

int	Bureaucrat::getGrade() const {
	return _grade;
}

void	Bureaucrat::upGrade(int amount) {
	
	try {
		checkGrade(_grade - amount);
		_grade -= amount;
	} catch (const Bureaucrat::GradeTooHighException & e) {
		std::cerr << "\n\nException: " << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException & i) {
		std::cerr << "\n\nException: " << i.what() << std::endl;
	}
}

void	Bureaucrat::downGrade(int amount) {
	try {
		checkGrade(_grade + amount);
		_grade += amount;
	} catch (const Bureaucrat::GradeTooHighException & e) {
		std::cerr << "\n\nException: " << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException & i) {
		std::cerr << "\n\nException: " << i.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm& form) {
	try {
		form.execute(*this);
		std::cout << getName() << " executed " << form.getName() << std::endl;
	} 
	catch (AForm::GradeTooHighException& high) {
		std::cerr << "Exception: " << high.what() << std::endl;
	} catch (AForm::GradeTooLowException& low) {
		std::cerr << "Exception: " << low.what() << std::endl;	
	} catch (AForm::FormNotSignedException& sign) {
		std::cerr << "Exception: " << sign.what() << std::endl;	
	}

}

void	Bureaucrat::signForm(const AForm& f) {
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
