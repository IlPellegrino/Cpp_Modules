#pragma once

# include <iostream>

class	Weapon {
	private:
		std::string type;

	public:
		Weapon(std::string type);
		~Weapon();

		void	setType(std::string tp);
		const std::string&	getType();
};
