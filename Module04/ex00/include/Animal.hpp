#pragma once

# include <iostream>
# include <string>

class	Animal {
	protected:
		std::string	type;

	public:
		Animal();
		Animal(const Animal& a);
		Animal&	operator=(const Animal& a);
		~Animal();

		void		setType(std::string type);

		std::string	getType() const;

		virtual void	makeSound() const;
};
