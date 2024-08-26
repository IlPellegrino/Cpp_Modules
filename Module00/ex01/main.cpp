#include "phonebook.hpp"

int	main()
{
	Contact		contact;
	PhoneBook	phoneBook;
	std::string	input;

	for (int i = 1; i == 1; i = 1)
	{
		std::cout << "Enter input: ";
		std::cin >> input;
		if (input == "EXIT")
			exit(0);
		else if (input == "ADD")
			phoneBook.addContact();
		else if (input == "SEARCH")
			phoneBook.displayContacts();
		else
			std::cout << "Command not found\n";
	}
	return (0);
}