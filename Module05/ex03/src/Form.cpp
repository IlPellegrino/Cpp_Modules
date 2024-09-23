#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"
#include <iostream>
#include <ostream>
#include <string>

Form::Form(const std::string name, const int signGrade, const int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
	try {
		checkGrade(signGrade);
		checkGrade(execGrade);
	} catch (const Form::GradeTooHighException &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	} catch (const Form::GradeTooLowException &i) {
		std::cerr << "Exception: " << i.what() << std::endl;
	}
}

Form::Form(const Form& f) : _name(f._name), _isSigned(f._isSigned), _signGrade(f._signGrade), _execGrade(f._execGrade) {
	std::cout << "COPY constructor has been called\n";
}

Form&	Form::operator=(const Form& f) {
	(std::string)this->_name = (std::string)f._name;
	this->_isSigned = f._isSigned;
	return *this;
}

Form::~Form() {
	std::cout << "Destructor has been called\n";
}

	// GETTERS //

std::string	Form::getName() const {
	return _name;
}

bool	Form::getIsSigned() const {
	return _isSigned;
}

int	Form::getSignGrade() const {
	return _signGrade;
}

int	Form::getExecGrade() const {
	return _execGrade;
}

const char * Form::GradeTooHighException::what() const throw() {
	return "Grade is too high!\n";
}

const char * Form::GradeTooLowException::what() const throw() {
	return "Grade is too low!\n";
}

const char *Form::FormNotSignedException::what() const throw() {
	return "Form is not signed!\n";
}

void	Form::beSigned(const Bureaucrat& b) {
	try {
		checkGrade(this->_signGrade);
		checkGrade(b.getGrade());
		if (b.getGrade() > this->_signGrade) {
			throw Form::GradeTooLowException();
		} else if (b.getGrade() <= this->_signGrade){
			_isSigned = true;
		}
	} catch (const Form::GradeTooHighException &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	} catch (const Form::GradeTooLowException &i) {
		std::cerr << "Exception: " << i.what() << std::endl;
	}
}

void	Form::checkGrade(int grade) const {
	if (grade < 1) {
		throw Form::GradeTooHighException();
	} else if (grade > 150) {
		throw Form::GradeTooLowException();
	}
}

std::ostream&	operator<<(std::ostream& os, const Form& f) {
	os << "-----Form Informations-----\n";
	os << "Name: " << f.getName() << "; Form is signed? -> " << (f.getIsSigned() ? "True;" : "False;") << std::endl;
	os << "Grade to sign this Form: " << f.getSignGrade() << std::endl;
	os << "Grade to execute this Form: " << f.getExecGrade() << std::endl;

	return os;
}