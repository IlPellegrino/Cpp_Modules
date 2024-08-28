/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:46:30 by nromito           #+#    #+#             */
/*   Updated: 2024/08/28 12:16:14 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <iomanip>
# include <limits>
# include "Contact.hpp"

# define RESET   "\033[0m"       // Reset all attributes (colors)
# define BLACK   "\033[30m"      // Black
# define RED     "\033[31m"      // Red
# define GREEN   "\033[32m"      // Green
# define YELLOW  "\033[33m"      // Yellow
# define BBLUE   "\033[94m"      // Bright Blue
# define BLUE    "\033[34m"      // Blue
# define MAGENTA "\033[35m"      // Magenta
# define CYAN    "\033[36m"      // Cyan
# define WHITE   "\033[37m"      // White

# define MAX_CONTACTS 8

class	PhoneBook
{	
	private:
		Contact	contacts[MAX_CONTACTS];
		int		currentIndex;
		int		_countContacts;

	public:
		PhoneBook();
		~PhoneBook();

		void	addContact();
		void	displayContacts();
		void	checker(std::string ref);
		bool	lettersChecker(std::string line);
};

#endif