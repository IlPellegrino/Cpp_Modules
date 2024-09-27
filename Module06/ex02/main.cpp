#include "include/Base.hpp"
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <typeinfo>

Base*	generate(void)
{
	int	num = rand() % 3;

	switch (num) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return NULL;
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p)) {
		std::cout << "A\n";
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "B\n";
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "C\n";
	} else {
		std::cout << "Unknown type\n";
	}
}

void	identify(Base& p)
{
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << &a << " is A\n";
		return;
	} catch (std::bad_cast&) {
		//do not do anything, try the others
	}
	try {
		B& b = dynamic_cast<B&>(p);
		std::cout << &b << " is B\n";
		return;
	} catch (std::bad_cast&) {
		//do not do anything, try the others
	}
	try {
		C& c = dynamic_cast<C&>(p);
		std::cout << &c << " is C\n";
		return;
	} catch (std::bad_cast&) {
		std::cout << "Unknown type\n";
	}
}

int	main()
{
	Base base;
	A a;
	B b;
	C c;

	Base *random = generate();
	Base *ran = generate();
	Base *gen = generate();

	identify(random);
	identify(ran);
	identify(gen);

	identify(base);
	identify(a);
	identify(b);
	identify(c);

	delete random;
	delete ran;
	delete gen;
}