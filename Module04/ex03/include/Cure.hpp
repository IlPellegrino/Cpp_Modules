#pragma once

# include <string>
#include "Character.hpp"
# include "Materia.hpp"

class	Cure : public AMateria {
	public:
		Cure();
		Cure(const Cure& c);
		Cure&	operator=(const Cure& c);
		~Cure();

		void		use(ICharacter& target);
		AMateria*	clone() const;
}