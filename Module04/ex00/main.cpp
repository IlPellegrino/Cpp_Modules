#include "include/Dog.hpp"
#include "include/Cat.hpp"
#include "include/Animal.hpp"

int	main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* w = new WrongAnimal();
	const WrongAnimal* c = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	w->makeSound();
	c->makeSound();

	delete meta;
	delete j;
	delete i;
	delete w;
	delete c;

	return 0;
}