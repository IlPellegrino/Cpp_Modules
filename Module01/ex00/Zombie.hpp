/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:08:05 by nromito           #+#    #+#             */
/*   Updated: 2024/08/29 14:26:45 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <iomanip>

class	Zombie {
	private:
		std::string	name;
		
	public:
		Zombie();
		~Zombie();
		
		Zombie*	newZombie(std::string name);
		void	announce(void);
		void	randomChump(std::string name);
};

#endif