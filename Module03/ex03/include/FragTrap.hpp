#pragma once

# include <iostream>
# include <string>
# include "../include/ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap {
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& ft);
		FragTrap&	operator=(const FragTrap& ft);
		~FragTrap();

		void	highFiveGuys(void);
};