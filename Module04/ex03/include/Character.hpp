#pragma once

# include <string>

# include "ICharacter.hpp"
# include "AMateria.hpp"
// # include "Materia.hpp"

class	AMateria;

class	ICharacter;

	// STANDARD CLASS //

class	Character : public ICharacter {
	private:
		static const int	N = 4;
		static const int	INV = 40;

	private:
		std::string		_name;
		AMateria*		_slots[N];
		AMateria*		_voidSlots[INV];
	
	public:
		Character();
		Character(const std::string& name);
		Character(const Character& c);
		Character&	operator=(const Character& c);
		~Character();

		std::string const &	getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);

		void				clearInventory();
		void				clearVoidSlots();
};