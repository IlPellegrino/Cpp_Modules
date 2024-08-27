/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:48:47 by nromito           #+#    #+#             */
/*   Updated: 2024/08/27 10:59:06 by nromito          ###   ########.fr       */
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
		std::string	_darkestSecret;

	public:
		Contact();
		~Contact();

		//SETTERS//
		void	setFirstName(const std::string  fn);
		void	setLastName(const std::string ln);
		void	setNickName(const std::string nn);
		void	setPhoneNumber(const std::string pn);
		void	setDarkestSecret(const std::string ds);
		void	setIndex(const int idx);

		//GETTERS//
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickName() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkestSecret() const;
		int			getIndex() const;
};

#endif