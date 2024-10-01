#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
#include <vector>

template <typename T>
bool	easyfind(T& a, int b)
{
	for (std::vector<int>::iterator it = a.begin(); it != a.end(); it++) {
		if (*it == b) {
			std::cout << *it << " has been found!\nIt's the same as " << b << std::endl;
			return true;
		}
	}
	std::cerr << "No occurrence found!\n";
	return false;
}


#endif