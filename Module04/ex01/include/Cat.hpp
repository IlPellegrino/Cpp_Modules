#pragma once

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define YELLOW "\033[33m"
# define MAGENTA "\033[35m"

class	Cat : public Animal {
	private:
		Brain	*brain;

	public:
		Cat();
		Cat(const Cat& c);
		Cat&	operator=(const Cat& c);
		~Cat();

		void	makeSound() const;
};
