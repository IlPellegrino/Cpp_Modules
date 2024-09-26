#include "../include/Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

uintptr_t	Serializer::serialize(Data *ptr)
{
	uintptr_t j = reinterpret_cast<uintptr_t>(ptr);
	return j;
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	Data *ptr = reinterpret_cast<Data*>(raw);
	return ptr;
}
