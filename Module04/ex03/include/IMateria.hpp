#pragma once

# include <iostream>
# include "AMateria.hpp"

class	AMateria;

	// INTERFACE //

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void		learnMateria(AMateria*) = 0;
		virtual AMateria*	createMateria(std::string const & type) = 0;
};