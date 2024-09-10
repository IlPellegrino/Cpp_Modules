#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include <iostream>
#include <ostream>
#include <string>

AForm::AForm(const std::string name, const int signGrade, const int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
	try {
		checkGrade(signGrade);
		checkGrade(execGrade);
	} catch (const AForm::GradeTooHighException &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	} catch (const AForm::GradeTooLowException &i) {
		std::cerr << "Exception: " << i.what() << std::endl;
	}
}

AForm::AForm(const AForm& f) : _name(f._name), _isSigned(f._isSigned), _signGrade(f._signGrade), _execGrade(f._execGrade) {
	std::cout << "COPY constructor has been called\n";
}

AForm&	AForm::operator=(const AForm& f) {
	(std::string)this->_name = (std::string)f._name;
	this->_isSigned = f._isSigned;
	return *this;
}

AForm::~AForm() {
	std::cout << "Destructor has been called\n";
}

	// GETTERS //

std::string	AForm::getName() const {
	return _name;
}

bool	AForm::getIsSigned() const {
	return _isSigned;
}

int	AForm::getSignGrade() const {
	return _signGrade;
}

int	AForm::getExecGrade() const {
	return _execGrade;
}

const char * AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high!\n";
}

const char * AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low!\n";
}

const char *AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed!\n";
}

void	AForm::beSigned(const Bureaucrat& b) {
	try {
		checkGrade(this->_signGrade);
		checkGrade(b.getGrade());
		if (b.getGrade() > this->_signGrade) {
			throw AForm::GradeTooLowException();
		} else if (b.getGrade() <= this->_signGrade){
			_isSigned = true;
		}
	} catch (const AForm::GradeTooHighException &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	} catch (const AForm::GradeTooLowException &i) {
		std::cerr << "Exception: " << i.what() << std::endl;
	}
}

void	AForm::checkGrade(int grade) const {
	if (grade < 1) {
		throw AForm::GradeTooHighException();
	} else if (grade > 150) {
		throw AForm::GradeTooLowException();
	}
}

std::ostream&	operator<<(std::ostream& os, const AForm& f) {
	os << "-----AForm Informations-----\n";
	os << "Name: " << f.getName() << "; Form is signed? -> " << (f.getIsSigned() ? "True;" : "False;") << std::endl;
	os << "Grade to sign this Form: " << f.getSignGrade() << std::endl;
	os << "Grade to execute this Form: " << f.getExecGrade() << std::endl;

	return os;
}