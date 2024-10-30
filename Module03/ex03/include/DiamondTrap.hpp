#pragma once

# include <iostream>
# include <string>
# include "../include/ScavTrap.hpp"
# include "../include/FragTrap.hpp"

class	DiamondTrap : virtual public ScavTrap, virtual public FragTrap {
	private:
		std::string	_name;

	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& dt);
		DiamondTrap&	operator=(const DiamondTrap& dt);
		~DiamondTrap();

		void	whoAmI();
		void	attack(const std::string& target);
};