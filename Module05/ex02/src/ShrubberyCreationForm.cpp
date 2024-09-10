#include "../include/ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "DEFAULT Shrubbery constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& scf) : AForm(scf) {
	_target = scf._target;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& scf) {
	this->_target = scf._target;

	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "DEFAULT SHRUBBERY destructor has been called\n";
}

std::string	ShrubberyCreationForm::getTarget() const {
	return _target;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const 
{
	checkGrade(executor.getGrade());
	if (executor.getGrade() > getSignGrade() || executor.getGrade() > getExecGrade()) {
		throw AForm::GradeTooLowException();
	}
	if (this->getIsSigned() == false) {
		throw  AForm::FormNotSignedException();
	}
	makeTrees();
}

void	ShrubberyCreationForm::makeTrees() const {
	std::ofstream	oFile;

	oFile.open((getTarget() + "_shrubbery").c_str());

	if (!oFile.is_open()) {
		std::cerr << "Error opening " << getTarget() + "_shrubbery" << " file\n";
		return;
	}

    oFile << "   ,\\\n";
    oFile << "    # (_\n";
    oFile << "      _)\\##\n";
    oFile << "  ###/((_ \n";
    oFile << "       ))\\####\n";
    oFile << "     _((     \n";
    oFile << "####/  )\\\n";
    oFile << "     ,;;\";,\n";
    oFile << "    (_______)\n";
    oFile << "      \\===/\n";
    oFile << "      /===\\\n";
    oFile << "     /=aat=\\\n";
    oFile << "                ,\\\n";
    oFile << "                 # (_\n";
    oFile << "                   _)\\##\n";
    oFile << "               ###/((_ \n";
    oFile << "                    ))\\####\n";
    oFile << "                  _((     \n";
    oFile << "               ####/  )\\\n";
    oFile << "                    ,;;\";,\n";
    oFile << "                   (_______)\n";
    oFile << "                     \\===/\n";
    oFile << "                     /===\\\n";
    oFile << "                    /=aat=\\\n";
	oFile.close();
}