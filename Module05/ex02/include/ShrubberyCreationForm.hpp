#pragma once

# include "AForm.hpp"
#include "Bureaucrat.hpp"
# include <string>

class	ShrubberyCreationForm : public AForm {
	private:
		std::string	_target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& scf);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& scf);
		~ShrubberyCreationForm();

		std::string	getTarget() const;

		void	makeTrees() const;
		void	execute(const Bureaucrat& executor) const;
};
