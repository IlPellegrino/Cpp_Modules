/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:46:30 by nromito           #+#    #+#             */
/*   Updated: 2024/08/19 13:19:09 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include "Contact.hpp"

# define MAX_CONTACTS 8

class	PhoneBook
{	
	private:
		Contact	contacts[MAX_CONTACTS];
		int		currentIndex;
	public:
		PhoneBook() : currentIndex(0) {}

		void	addContact(const  Contact& contact)
		{
			contacts[currentIndex] = contact;
			currentIndex = (currentIndex + 1) % 8;
		}

		void	displayContacts();
};

#endif