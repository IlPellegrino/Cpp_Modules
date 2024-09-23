#pragma once

# include "Form.hpp"
# include "Bureaucrat.hpp"

class	RobotomyRequestForm : public Form {
	private:
		std::string	_target;

	public:
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& rrf);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& rrf);
		~RobotomyRequestForm();

		std::string	getTarget() const;

		void	makeNoise() const;
		void	execute(const Bureaucrat& executor) const;
};