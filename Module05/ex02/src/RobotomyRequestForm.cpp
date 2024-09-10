#include "../include/RobotomyRequestForm.hpp"
#include <iostream>
#include <string>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "DEFAULT Robotomy constructor has been called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rrf) : AForm(rrf) {
	_target = rrf.getTarget();
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& rrf) {
	this->_target = rrf.getTarget();
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

	std::cout << getTarget() << "has been robotomized successfully 50% of the time\n";
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	try 
	{
		checkGrade(executor.getGrade());
		if (executor.getGrade() > getSignGrade() || executor.getGrade() > getExecGrade()) {
			throw AForm::GradeTooLowException();
		}
		if (this->getIsSigned() == false) {
			throw AForm::FormNotSignedException();
		}
		makeNoise();
	} catch (AForm::GradeTooHighException& high) {
		std::cerr << "Exception: " << high.what() << std::endl << "Robotomy failed -> :(\n";
	} catch (AForm::GradeTooLowException& low) {
		std::cerr << "Exception: " << low.what() << std::endl << "Robotomy failed -> :(\n";	
	} catch (AForm::FormNotSignedException& sign) {
		std::cerr << "Exception: " << sign.what() << std::endl << "Robotomy failed -> :(\n";	
	}
}