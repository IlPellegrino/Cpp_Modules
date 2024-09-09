#pragma once

# include <exception>
# include <ostream>
# include <string>

class	Form;

class	Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& b);
		Bureaucrat&	operator=(const Bureaucrat& b);
		~Bureaucrat();

		void	setGrade(int grade);

		std::string	getName() const;
		int			getGrade() const;

		class	GradeTooHighException : public std::exception {
			public:
				virtual const char * what() const throw();
		};

		class	GradeTooLowException : public std::exception {
			public:
				virtual const char * what() const throw();
		};

		void	upGrade(int amount);
		void	downGrade(int amount);
		void	checkGrade(int grade);
		void	signForm(const Form& f);
};

std::ostream&	operator<<(std::ostream& os, Bureaucrat& b);