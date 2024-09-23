#pragma once

# include <string>
# include "Materia.hpp"

class ICharacter
{
	public:
		ICharacter();
		ICharacter(const ICharacter& c);
		ICharacter&	operator=(const ICharacter& c);
		virtual ~ICharacter() {}

		virtual std::string const&	getName() const = 0;
		virtual void				equip(AMateria* m) = 0;
		virtual void				unequip(int idx) = 0;
		virtual void				use(int idx, ICharacter& target) = 0;
};

class	Character : public ICharacter {
	
}