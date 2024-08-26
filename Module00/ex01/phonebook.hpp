/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:46:30 by nromito           #+#    #+#             */
/*   Updated: 2024/08/26 15:41:04 by nromito          ###   ########.fr       */
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
		PhoneBook();
		~PhoneBook();

		void	addContact();
		void	displayContacts();
};

#endif