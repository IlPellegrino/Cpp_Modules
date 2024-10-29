/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:08:05 by nromito           #+#    #+#             */
/*   Updated: 2024/10/29 11:19:29 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <iomanip>

class	Zombie {
	private:
		std::string	_name;
		
	public:
		Zombie(std::string name);
		~Zombie();
		
		void	announce(void);
};

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

#endif