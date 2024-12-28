/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:35:08 by txisto-d          #+#    #+#             */
/*   Updated: 2024/11/22 22:13:11 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int	main(void)
{
	int			size;
	int			i;
	std::string	name;
	Zombie*		horde;
	
	i = 0;
	size = 0;
	name = "Claudio";
	horde = zombieHorde(size, name);
	while (i < size)
	{
		horde[i].announce();
		i++;
	}
	delete [] horde;
}