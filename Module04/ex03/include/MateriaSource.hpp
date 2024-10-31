#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"
# include "IMateria.hpp"
# include <string>

// # include "IMateria.hpp"

class	IMateriaSource;

class	AMateria;

	// STANDARD CLASS //

class	MateriaSource : public IMateriaSource
{
	private:
		static const int	N = 4;
		AMateria	*_knowledge[N];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& ms);
		MateriaSource&	operator=(const MateriaSource& ms);
		~MateriaSource();

		void		learnMateria(AMateria* m);
		AMateria*	createMateria(std::string const & type);

		void	clearKnowledge();
};

#endif