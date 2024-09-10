#pragma once

# include "Bureaucrat.hpp"
# include <exception>
# include <ostream>
# include <string>

class	Bureaucrat;

class	AForm {
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;

	public:
		AForm(const std::string name, const int signGrade, const int execGrade);
		AForm(const AForm& f);
		AForm&	operator=(const AForm& f);
		~AForm();

		std::string	getName() const;
		bool		getIsSigned() const;
		int			getSignGrade() const;
		int			getExecGrade() const;

		class	GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class	GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class	FormNotSignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		virtual void	execute(const Bureaucrat& executor) const = 0;
		virtual void	beSigned(const Bureaucrat& b);
		virtual void	checkGrade(int grade) const;
};

std::ostream&	operator<<(std::ostream& os, const AForm& f);
