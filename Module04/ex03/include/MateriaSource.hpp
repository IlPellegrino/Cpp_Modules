#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <string>

# include "IMateria.hpp"

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

		// MateriaSource known[2]
		// known[0] = AMateria;
		// createMateria -> known[i].getType == type;
		void		learnMateria(AMateria* m);
		AMateria*	createMateria(std::string const & type);
};

#endif