#include "../include/RobotomyRequestForm.hpp"
#include <iostream>
#include <string>

RobotomyRequestForm::RobotomyRequestForm()
	: Form("RobotomyRequestForm", 72, 45), _target("Default target")
{
	std::cout << "DEFAULT Robotomy constructor has been called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: Form("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "Robotomy constructor has been called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rrf) : Form(rrf) {
	_target = rrf._target;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& rrf) {
	this->_target = rrf._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Robotomy destructor has been called\n";
}

std::string	RobotomyRequestForm::getTarget() const {
	return _target;
}

void	RobotomyRequestForm::makeNoise() const {
	std::cout << "Bzzz....Fzzzz....Pzzzz....\n\n\n";

	std::cout << getTarget() << " has been robotomized successfully 50% of the time\n";
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	checkGrade(executor.getGrade());
	if (executor.getGrade() > getSignGrade() || executor.getGrade() > getExecGrade()) {
		throw Form::GradeTooLowException();
	}
	if (this->getIsSigned() == false) {
		throw Form::FormNotSignedException();
	}
	makeNoise();
}