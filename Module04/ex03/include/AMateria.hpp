#pragma once

# include <iostream>

# include "ICharacter.hpp"

class	ICharacter;

	// ABSTRACT CLASS //

class AMateria {
	protected:
		std::string	_type;

	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria& m);
		AMateria&	operator=(const AMateria& m);
		virtual ~AMateria();

		virtual AMateria*	clone() const = 0;
		void				setType(std::string const & type);
		std::string const&	getType() const; //Returns the materia type
		virtual void		use(ICharacter& target);
};