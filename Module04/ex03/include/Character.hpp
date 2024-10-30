#pragma once

# include <string>
# include "AMateria.hpp"
# include "Materia.hpp"

	// STANDARD CLASS //

class	Character : public ICharacter {
	private:
		std::string		_name;
		AMateria	*_slots[4];
		// ice [0] 
		// use idx target
		// slots[0].use(target); use ** std::cout << balab << target.getName()
	
	public:
		Character(std::string& name);
		Character(const Character& c);
		Character&	operator=(const Character& c);
		~Character();

		std::string const &	getName();
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};