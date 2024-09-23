#pragma once

# include "Bureaucrat.hpp"
# include <exception>
# include <ostream>
# include <string>

class	Bureaucrat;

class	Form {
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;

	public:
		Form(const std::string name, const int signGrade, const int execGrade);
		Form(const Form& f);
		Form&	operator=(const Form& f);
		virtual	~Form();

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

std::ostream&	operator<<(std::ostream& os, const Form& f);
