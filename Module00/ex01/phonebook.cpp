/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:46:13 by nromito           #+#    #+#             */
/*   Updated: 2024/08/26 15:31:41 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook() : currentIndex(0) {}

void	PhoneBook::addContact()
{
	std::string	line;

	if (currentIndex == 8) {
		currentIndex = 0;
	}

	for (int i = 0; i < 5; i++)
	{
		std::cout << "Enter First Name: ";
		std::cin >> line;
		contacts[currentIndex].setFirstName(line);
		
		std::cout << "Enter Last Name: ";
		std::cin >> line;
		contacts[currentIndex].setLastName(line);

		std::cout << "Enter nickname: ";
		std::cin >> line;
		contacts[currentIndex].setNickName(line);

		std::cout << "Enter Phone Number: ";
		std::cin >> line;
		contacts[currentIndex].setPhoneNumber(line);

		std::cout << "Enter Darkest Secret:";
		std::cin >> line;
		contacts[currentIndex].setDarkestSecret(line);
	}
	currentIndex++;
}

void	PhoneBook::displayContacts()
{
	
}
