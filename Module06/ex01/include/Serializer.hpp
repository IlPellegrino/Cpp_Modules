#pragma once

# include <string>

typedef unsigned long int uintptr_t;

typedef struct Data {
	int			i;
	std::string	s;
}			Data;

class	Serializer {
	private:
		Serializer();
		virtual ~Serializer() = 0;
	
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*	deserialize(uintptr_t raw);
};
