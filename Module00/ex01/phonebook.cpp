/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:46:13 by nromito           #+#    #+#             */
/*   Updated: 2024/08/19 13:12:47 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	add(PhoneBook& pb, Contact& contact)
{
	std::string	line;

	for (int i = 0; i < 5; i++)
	{
		if (i == 0)
		{
			std::cout << "Enter First Name: ";
			std::cin >> line;
			contact.setFirstName(line);
		}
		else if (i == 1)
		{
			std::cout << "Enter Last Name: ";
			std::cin >> line;
			contact.setLastName(line);
		}
		else if (i == 2)
		{
			std::cout << "Enter nickname: ";
			std::cin >> line;
			contact.setNickName(line);
		}
		else if (i == 3)
		{
			std::cout << "Enter Phone Number: ";
			std::cin >> line;
			contact.setPhoneNumber(line);
		}
		else if (i == 4)
		{
			std::cout << "Enter Darkest Secret:";
			std::cin >> line;
			contact.setDarkestSecret(line);
		}
	}
	pb.addContact(contact);
}

void	search()
{
	
}

int	main()
{
	Contact		contact;
	PhoneBook	pb;
	std::string	input;

	for (int i = 1; i == 1; i = 1)
	{
		std::cout << "Enter input: ";
		std::cin >> input;
		if (input == "EXIT")
			exit(0);
		else if (input == "ADD")
			add(pb, contact);
		else if (input == "SEARCH")
			exit(0);
		else
			std::cout << "Command not found\n";
	}
	return (0);
}
