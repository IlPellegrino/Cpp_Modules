#pragma once

# include "Form.hpp"
# include <string>


class	Intern {
	public:
		Intern();
		Intern(const Intern& i);
		Intern&	operator=(const Intern& i);
		~Intern();

		Form*	makeForm(std::string name, std::string target);
};