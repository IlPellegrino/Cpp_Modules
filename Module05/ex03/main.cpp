#include "include/Bureaucrat.hpp"
#include "include/Intern.hpp"
#include "include/Form.hpp"
#include <iostream>

int	main()
{
	Bureaucrat	lawyer("gino", 25);
	Bureaucrat	medic("pino", 56);
	Bureaucrat	carpenter("andrea", 10);

	Intern someRandomIntern;

	Form* rrf;
	Form* ppf;
	Form* scf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	ppf = someRandomIntern.makeForm("presidential pardon", "STASSIONE");
	scf = someRandomIntern.makeForm("Shrubbery Creation", "Hack");

	ppf->beSigned(medic);

	ppf->execute(medic);

	scf->beSigned(carpenter);

	scf->execute(carpenter);

	rrf->beSigned(lawyer);

	rrf->execute(lawyer);

	delete rrf;
	delete ppf;
	delete scf;
}