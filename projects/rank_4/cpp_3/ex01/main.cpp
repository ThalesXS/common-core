/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:45:02 by txisto-d          #+#    #+#             */
/*   Updated: 2024/05/21 13:36:12 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap poorThing;
	ScavTrap clone("Hyperion B1");
	ScavTrap multiply(clone);
	while (poorThing.getAttribute(HP) > 0 && poorThing.getAttribute(EP) > 0)
	{
		poorThing.attack("Loader");
		poorThing.takeDamage(20);
		poorThing.beRepaired(5);
	}
	clone = poorThing;
	poorThing.attack("Loader");
	poorThing.guardGate();
	multiply.guardGate();
	return (0);
}