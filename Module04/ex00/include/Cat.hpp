#pragma once

# include <iostream>
# include <string>
# include "Animal.hpp"

class	Cat : public Animal {
	public:
		Cat();
		Cat(const Cat& c);
		Cat&	operator=(const Cat& c);
		~Cat();

		void	makeSound() const;
};

class	WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(const WrongCat& c);
		WrongCat&	operator=(const WrongCat& c);
		~WrongCat();

		void	makeSound() const;
};
