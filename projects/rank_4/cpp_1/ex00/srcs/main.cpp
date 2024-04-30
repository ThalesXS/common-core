/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:35:08 by txisto-d          #+#    #+#             */
/*   Updated: 2024/04/30 21:02:42 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
int	main(void)
{
	Zombie *yourZombie;
	yourZombie = newZombie("Emanuel");
	yourZombie->announce();
	randomChump("The Champion");
	delete (yourZombie);
}