#pragma once

#include "AMateria.hpp"
# include "IMateria.hpp"
# include <string>

	// STANDARD CLASS //

class	MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_knowledge[4];


	public:
		MateriaSource();
		MateriaSource(const MateriaSource& ms);
		MateriaSource&	operator=(const MateriaSource& ms);
		~MateriaSource();

		// MateriaSource known[2]
		// known[0] = AMateria;
		// createMateria -> known[i].getType == type;
		void		learnMateria(AMateria* m);
		AMateria*	createMateria(std::string const & type);
};