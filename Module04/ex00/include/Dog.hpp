#pragma once

# include <iostream>
# include <string>
# include "Animal.hpp"

class	Dog : public Animal {
	public:
		Dog();
		Dog(const Dog& d);
		Dog&	operator=(const Dog& d);
		~Dog();

		void	makeSound() const;
};
