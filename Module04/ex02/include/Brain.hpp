#pragma once

# include <iostream>
# include <string>

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define YELLOW "\033[33m"
# define MAGENTA "\033[35m"

class	Brain {
	private:
		std::string	_ideas[100];

	public:
		Brain();
		Brain(const Brain& b);
		Brain&	operator=(const Brain& b);
		~Brain();


};