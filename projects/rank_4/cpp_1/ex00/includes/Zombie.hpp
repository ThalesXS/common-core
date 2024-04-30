/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:35:06 by txisto-d          #+#    #+#             */
/*   Updated: 2024/04/30 21:01:38 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie;

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

class Zombie
{
	public:
		Zombie(std::string zombie);
		~Zombie();
		void	announce(void);
	private:
		std::string name;
};

#endif