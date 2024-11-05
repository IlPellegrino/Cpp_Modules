#pragma once

# include "Form.hpp"
# include "Bureaucrat.hpp"

class	RobotomyRequestForm : public Form {
	private:
		std::string	_target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& rrf);
		~RobotomyRequestForm();

		RobotomyRequestForm& operator=(const RobotomyRequestForm& rrf);

		std::string	getTarget() const;

		void	makeNoise() const;
		void	execute(const Bureaucrat& executor) const;
};