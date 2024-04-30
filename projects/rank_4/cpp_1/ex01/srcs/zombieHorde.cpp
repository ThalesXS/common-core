/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:08:33 by txisto-d          #+#    #+#             */
/*   Updated: 2024/04/30 21:38:19 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	int i;
	Zombie *horde;

	i = 0;
	horde = new Zombie[N];
	while (i < N)
	{
		horde[i] = Zombie(name);
		i++;
	}
	return (horde);
}