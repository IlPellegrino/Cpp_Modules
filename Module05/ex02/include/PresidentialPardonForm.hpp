#pragma once

# include "AForm.hpp"
# include "Bureaucrat.hpp"
#include <string>

class	PresidentialPardonForm : public AForm {
	private:
		std::string	_target;

	public:
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& ppf);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& ppf);
		~PresidentialPardonForm();

		std::string	getTarget() const;

		void	execute(const Bureaucrat& executor) const;
		void	makePardon() const;
};