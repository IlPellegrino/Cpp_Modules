/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:48:47 by nromito           #+#    #+#             */
/*   Updated: 2024/08/19 13:37:14 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
	private:
		int			_index;
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;\

	public:
		Contact();
		~Contact();

		void	setFirstName(const std::string  fn) { _firstName = fn; }
		void	setLastName(const std::string ln) { _lastName = ln; }
		void	setNickName(const std::string nn) { _nickName = nn; }
		void	setPhoneNumber(std::string pn) { _phoneNumber = pn; }
		void	setDarkestSecret(std::string ds) { _darkestSecret = ds; }
		void	setIndex(const int in) { _index = in; }
};

#endif