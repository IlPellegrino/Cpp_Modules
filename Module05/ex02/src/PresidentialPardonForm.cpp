#include "../include/PresidentialPardonForm.hpp"
#include <iostream>
#include <string>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "DEFAULT Pardon constructor has been called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ppf) : AForm(ppf) {
	_target = ppf.getTarget();
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& ppf) {
	this->_target = ppf.getTarget();
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Pardon destructor has been called\n";
}

std::string	PresidentialPardonForm::getTarget() const {
	return _target;
}

void	PresidentialPardonForm::makePardon() const {
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox.\n";
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	checkGrade(executor.getGrade());
	if (executor.getGrade() > getSignGrade() || executor.getGrade() > getExecGrade()) {
		throw AForm::GradeTooLowException();
	}
	if (this->getIsSigned() == false) {
		throw AForm::FormNotSignedException();
	}
	makePardon();
}