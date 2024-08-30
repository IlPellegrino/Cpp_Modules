#pragma once

# include <iostream>
# include "Weapon.hpp"

class	HumanB {
	private:
		std::string	name;
		Weapon		*weapon;
	
	public:
		HumanB(std::string s);
		~HumanB();

		void	attack();
		void	setWeapon(Weapon& w);
};