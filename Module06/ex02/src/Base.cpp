#include "../include/Base.hpp"
#include <iostream>

Base::~Base() {}

A::A() {
	std::cout << "class A instantiated\n";
}

A::~A() {
	std::cout << "A destroyed\n";
}

B::B() {
	std::cout << "class B instantiated\n";
}

B::~B() {
	std::cout << "B destroyed\n";
}

C::C() {
	std::cout << "class C instantiated\n";
}

C::~C() {
	std::cout << "C destroyed\n";
}
