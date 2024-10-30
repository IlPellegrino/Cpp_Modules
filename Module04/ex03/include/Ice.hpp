#pragma once

# include <string>
# include <iostream>
# include "AMateria.hpp"

class	Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice& i);
		Ice&	operator=(const Ice& i);
		~Ice();

		void		use(ICharacter& target);
		AMateria*	clone() const;
};