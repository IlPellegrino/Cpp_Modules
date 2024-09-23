#pragma once

# include <string>
# include "Materia.hpp"

class	Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice& i);
		Ice&	operator=(const Ice& i);
		~Ice();

};