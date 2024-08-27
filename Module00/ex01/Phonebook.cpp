/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:46:13 by nromito           #+#    #+#             */
/*   Updated: 2024/08/27 20:10:47 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

//check per i numeri e le stringhe
// fare vari test anche con ctrlD

PhoneBook::PhoneBook() : currentIndex(-1) {}

PhoneBook::~PhoneBook() {}

void	PhoneBook::addContact()
{
	std::string	line;

	if (currentIndex == 8 || currentIndex < 0) {
		currentIndex = 0;
	}

	while (1)
	{
		std::cout << "Enter First Name: ";
		if (getline(std::cin, line).eof()) {
			exit(0);
		}
		else if (line.empty()){
			std::cerr << RED << "Field cannot be empty\n" << RESET;
			continue;
		}
		contacts[currentIndex].setFirstName(line);
		
		std::cout << "Enter Last Name: ";
		if (getline(std::cin, line).eof()) {
			exit(0);
		}
		else if (line.empty()){
			std::cerr << RED << "Invalid input\n" << RESET;
			continue;
		}
		contacts[currentIndex].setLastName(line);

		std::cout << "Enter nickname: ";
		if (getline(std::cin, line).eof()) {
			exit(0);
		}
		else if (line.empty()){
			std::cerr << RED << "Invalid input\n" << RESET;
			continue;
		}
		contacts[currentIndex].setNickName(line);

		std::cout << "Enter Phone Number: ";
		if (getline(std::cin, line).eof()) {
			exit(0);
		}
		else if (line.empty()){
			std::cerr << RED << "Invalid input\n" << RESET;
			continue;
		}
		contacts[currentIndex].setPhoneNumber(line);

		std::cout << "Enter Darkest Secret:";
		if (getline(std::cin, line).eof()) {
			exit(0);
		}
		else if (line.empty()){
			std::cerr << RED << "Invalid input\n" << RESET;
			continue;
		}
		contacts[currentIndex].setDarkestSecret(line);
		contacts[currentIndex].setIndex(currentIndex);
		break;
	}
	currentIndex++;
}

void	PhoneBook::checker(std::string ref) {
	if (ref.length() > 10) {
		ref = ref.substr(0, 9) + ".";
	}
	std::cout << std::setw(10) << ref;
}

void	PhoneBook::displayContacts()
{
	std::string	line;
	int			input;

	if (currentIndex == -1) {
		std::cerr << RED << "PhoneBook empty, please add some contacts ;)" << RESET << std::endl;
		return;
	}
	else {
		std::cout << std::setw(10) << BLUE << "Index" << WHITE << "|" << RESET;
		std::cout << YELLOW << "First Name" << WHITE << "|" << RESET;
		std::cout << MAGENTA << "Last  Name" << WHITE << "|" << RESET;
		std::cout << GREEN << "Nick  Name" << RESET << "|" <<  std::endl;
		for (int i = 0; i < currentIndex; i++) {
			std::cout << std::setw(10) << contacts[i].getIndex();
			std::cout << "|";
			checker(contacts[i].getFirstName());
			std::cout << "|";
			checker(contacts[i].getLastName());
			std::cout << "|";
			checker(contacts[i].getNickName());
			std::cout << "|";
			std::cout << std::endl;
		}
	}
	while (1) {
		std::cout << CYAN << "Please insert the Contact index: ";
		if (getline(std::cin, line).eof())
			exit(0);
		std::cin >> line;
		if (line.empty())
			break;
		std::cin >> input;
		if (input < 8 && input >= 0 && input < currentIndex) {
			std::cout << BBLUE << "First Name: " << RESET << contacts[input].getFirstName() << std::endl;
			std::cout << BBLUE << "Last Name: " << RESET << contacts[input].getLastName() << std::endl;
			std::cout << BBLUE << "Nick Name: " << RESET << contacts[input].getNickName() << std::endl;
			std::cout << BBLUE << "Phone Number: " << RESET << contacts[input].getPhoneNumber() << std::endl;
			std::cout << BBLUE << "Darkest Secret: " << RESET << contacts[input].getDarkestSecret() << std::endl;
		}
		else {
			std::cerr << RED << "Contact index doesn't exist :(" << std::endl;
		}
	}
}
