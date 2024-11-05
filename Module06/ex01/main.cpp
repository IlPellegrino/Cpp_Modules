#include "include/Serializer.hpp"
#include <iostream>

int	main()
{
	Data		*d = new Data;
	Data		*result;
	uintptr_t	num;

	d->s = "mi chiamo Gianni\n";
	num = Serializer::serialize(d);
	result = Serializer::deserialize(num);
	result->s = "ciao come va?\n";
	if (d == result) {
		std::cout << "THEY ARE THE SAME!!!\n";
		std::cout << d << " " << d->s << std::endl;
		std::cout << result << " " << result->s << std::endl;
	} else {
		std::cout << "THEY ARE NOT THE SAME!!!\n";
		std::cout << d << std::endl;
		std::cout << result << std::endl;
	}
	delete result;
}