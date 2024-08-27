#include "phonebook.hpp"

int	main()
{
	Contact		contact;
	PhoneBook	phoneBook;
	std::string	input;

	while (1)
	{
		std::cout << CYAN << "Enter input -> [ADD] | [SEARCH] | [EXIT]: " << RESET;
		if (getline(std::cin, input).eof())
			exit(0);
		if (input == "EXIT")
			exit(0);
		else if (input == "ADD")
			phoneBook.addContact();
		else if (input == "SEARCH")
			phoneBook.displayContacts();
		else
			std::cout << RED << "Command not found\n" << RESET;
	}
	return (0);
}