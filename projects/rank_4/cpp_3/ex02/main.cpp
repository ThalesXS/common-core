/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:45:02 by txisto-d          #+#    #+#             */
/*   Updated: 2024/08/24 10:02:55 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ScavTrap poorThing;
	FragTrap ninja;
	poorThing.attack("Loader");
	ninja.highFivesGuys();
	while (ninja.getAttribute(HP) > 0 && ninja.getAttribute(EP) > 0)
	{
		ninja.attack("Loader");
		ninja.takeDamage(20);
		ninja.beRepaired(5);
	}
	ninja.attack("Loader");
	poorThing.guardGate();
	ninja.highFivesGuys();
	return (0);
}