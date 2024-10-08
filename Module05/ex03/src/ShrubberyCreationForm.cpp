#include "../include/ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "DEFAULT Shrubbery constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& scf) : Form(scf) {
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
    try {
        checkGrade(executor.getGrade());
        if (executor.getGrade() > getSignGrade() || executor.getGrade() > getExecGrade()) {
            throw Form::GradeTooLowException();
        }
        if (this->getIsSigned() == false) {
            throw  Form::FormNotSignedException();
        }
        makeTrees();
    } catch (Form::GradeTooHighException& high) {
		std::cerr << "Exception: " << high.what() << std::endl << "Robotomy failed -> :(\n";
	} catch (Form::GradeTooLowException& low) {
		std::cerr << "Exception: " << low.what() << std::endl << "Robotomy failed -> :(\n";	
	} catch (Form::FormNotSignedException& sign) {
		std::cerr << "Exception: " << sign.what() << std::endl << "Robotomy failed -> :(\n";	
	}
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