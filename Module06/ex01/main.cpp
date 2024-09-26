#include "include/Serializer.hpp"
#include <iostream>

int	main()
{
	Data		*d = new Data;
	Data		*result;
	uintptr_t	num;

	num = Serializer::serialize(d);
	result = Serializer::deserialize(num);
	if (d == result) {
		std::cout << "THEY ARE THE SAME!!!\n";
		std::cout << d << std::endl;
		std::cout << result << std::endl;
	} else {
		std::cout << "THEY ARE NOT THE SAME!!!\n";
		std::cout << &d << std::endl;
		std::cout << &result << std::endl;
	}
	delete result;
}