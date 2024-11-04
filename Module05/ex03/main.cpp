#include "include/Bureaucrat.hpp"
#include "include/Intern.hpp"
#include "include/Form.hpp"
#include <cstddef>
#include <iostream>

int	main()
{
	Form* rrf = NULL;
	Form* ppf = NULL;
	Form* scf = NULL;

	try {

		Bureaucrat	lawyer("gino", 72);
		Bureaucrat	medic("pino", 56);
		Bureaucrat	carpenter("andrea", 10);

		Intern someRandomIntern;


		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		ppf = someRandomIntern.makeForm("presidential pardon", "STASSIONE");
		scf = someRandomIntern.makeForm("Shrubbery Creation", "Hack");

		ppf->beSigned(medic);

		ppf->execute(medic);

		scf->beSigned(carpenter);

		scf->execute(carpenter);

		rrf->beSigned(lawyer);

		rrf->execute(lawyer);
	
	} catch (Form::GradeTooHighException& high) {
		std::cerr << high.what() << std::endl;
	} catch (Form::GradeTooLowException& low) {
		std::cerr << low.what() << std::endl;	
	} catch (Form::FormNotSignedException& sign) {
		std::cerr << sign.what() << std::endl;
	} catch (Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what();
	} catch (Bureaucrat::GradeTooLowException& i) {
		std::cerr << i.what();
	}

	delete rrf;
	delete ppf;
	delete scf;
}