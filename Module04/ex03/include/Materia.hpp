#pragma once

# include <string>
# include "Character.hpp"

class AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria& m);
		AMateria&	operator=(const AMateria& m);
		~AMateria();

		virtual AMateria*	clone() const = 0;
		void				setType(std::string const & type);
		std::string const&	getType() const; //Returns the materia type
		virtual void		use(ICharacter& target);
};

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void		learnMateria(AMateria*) = 0;
		virtual AMateria*	createMateria(std::string const & type) = 0;
};

class	MateriaSource : public IMateriaSource {
	private:

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& ms);
		MateriaSource&	operator=(const MateriaSource& ms);
		~MateriaSource();

		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const & type);		
};