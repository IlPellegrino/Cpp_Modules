/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:46:13 by nromito           #+#    #+#             */
/*   Updated: 2024/08/26 15:49:53 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook() : currentIndex(0) {}

PhoneBook::~PhoneBook() {}

void	PhoneBook::addContact()
{
	std::string	line;

	if (currentIndex == 8) {
		currentIndex = 0;
	}

	while (1)
	{
		std::cout << "Enter First Name: ";
		if (getline(std::cin, line).eof() || line.empty())
			std::cerr << "Invalid input\n";
		contacts[currentIndex].setFirstName(line);
		
		std::cout << "Enter Last Name: ";
		if (getline(std::cin, line).eof() || line.empty())
			std::cerr << "Invalid input\n";
		contacts[currentIndex].setLastName(line);

		std::cout << "Enter nickname: ";
		if (getline(std::cin, line).eof() || line.empty())
			std::cerr << "Invalid input\n";
		contacts[currentIndex].setNickName(line);

		std::cout << "Enter Phone Number: ";
		if (getline(std::cin, line).eof() || line.empty())
			std::cerr << "Invalid input\n";
		contacts[currentIndex].setPhoneNumber(line);

		std::cout << "Enter Darkest Secret:";
		if (getline(std::cin, line).eof() || line.empty())
			std::cerr << "Invalid input\n";
		contacts[currentIndex].setDarkestSecret(line);
	}
	currentIndex++;
}

void	PhoneBook::displayContacts()
{
	
}
