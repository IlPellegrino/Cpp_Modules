#include "include/Dog.hpp"
#include "include/Cat.hpp"
#include "include/Animal.hpp"
#include "include/Brain.hpp"

// int	main()
// {
// 	const Animal* animals[10];

// 	for (size_t i = 0; i < 10; i++)
// 	{
// 		if (i < 5) {
// 			animals[i] = new Dog();
// 		} else {
// 			animals[i] = new Cat();
// 		}
// 	}

// 	for (size_t i = 0; i < 10; i++) {
// 		animals[i]->makeSound();
// 	}
		

// 	for (size_t i = 0; i < 10; i++) {
// 		delete animals[i];
// 	}

// 	return 0;
// }

int	main()
{
	// const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	// meta->makeSound();

	delete j;
	delete i;

	return 0;
}