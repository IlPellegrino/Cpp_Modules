/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:48:14 by nromito           #+#    #+#             */
/*   Updated: 2024/08/26 14:25:37 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void PhoneBook::addContact(const  Contact& contact)
{
	contact.[currentIndex] = contact;
	currentIndex = (currentIndex + 1) % 8;
}