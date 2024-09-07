#pragma once

# include <iostream>
# include <string>

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define YELLOW "\033[33m"
# define MAGENTA "\033[35m"

class	Animal {
	protected:
		std::string	type;

	public:
		Animal();
		Animal(const Animal& a);
		Animal&	operator=(const Animal& a);
		virtual	~Animal();

		void		setType(std::string type);

		std::string	getType() const;

		virtual void	makeSound() const;
};
