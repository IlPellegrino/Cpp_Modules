#pragma once

# include <iostream>
# include <string>
# include "../include/ClapTrap.hpp"

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define YELLOW "\033[33m"
# define MAGENTA "\033[35m"

class	ScavTrap : virtual public ClapTrap {
	private:

	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& st);
		ScavTrap&	operator=(const ScavTrap& st);
		~ScavTrap();

		void	guardGate();
		void	attack(const std::string& target);
};