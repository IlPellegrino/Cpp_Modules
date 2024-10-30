#pragma once

# include <string>

# include "ICharacter.hpp"
# include "AMateria.hpp"
// # include "Materia.hpp"

	// STANDARD CLASS //

class	Character : public ICharacter {
	private:
		static const int	N = 4;
		static const int	INV = 40;

	private:
		std::string		_name;
		AMateria*		_slots[N];
		AMateria*		_voidSlots[INV];
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