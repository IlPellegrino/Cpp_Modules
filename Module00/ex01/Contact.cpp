/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:48:14 by nromito           #+#    #+#             */
/*   Updated: 2024/08/27 10:44:06 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void	Contact::setFirstName(const std::string fn) {
	_firstName = fn;
}

void	Contact::setLastName(const std::string ln) {
	_lastName = ln;
}

void	Contact::setNickName(const std::string nn) {
	_nickName = nn;
}

void	Contact::setPhoneNumber(const std::string pn) {
	_phoneNumber = pn;
}

void	Contact::setDarkestSecret(const std::string ds) {
	_darkestSecret = ds;
}

void	Contact::setIndex(const int idx) {
	_index = idx;
}

std::string	Contact::getFirstName() const {
	return (_firstName);
}

std::string	Contact::getLastName() const {
	return (_lastName);
}

std::string	Contact::getNickName() const {
	return (_nickName);
}

std::string	Contact::getPhoneNumber() const {
	return (_phoneNumber);
}

std::string	Contact::getDarkestSecret() const {
	return (_darkestSecret);
}

int	Contact::getIndex() const {
	return (_index);
}