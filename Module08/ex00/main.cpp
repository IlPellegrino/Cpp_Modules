#include "include/easyfind.hpp"
#include <vector>

int	main()
{
	std::vector<int>	v;

	v.push_back(100);
	v.push_back(24);
	v.push_back(31);
	v.push_back(3);
	v.push_back(10);
	v.push_back(324);


	if (!easyfind(v, 10))
		return (1);
	return (0);
}