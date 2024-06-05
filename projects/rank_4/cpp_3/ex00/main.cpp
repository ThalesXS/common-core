/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:45:02 by txisto-d          #+#    #+#             */
/*   Updated: 2024/05/21 13:24:48 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap poorThing;
	ClapTrap clone("Hyperion B1");
	ClapTrap multiply(clone);
	while (poorThing.getAttribute(HP) > 0 && poorThing.getAttribute(EP) > 0)
	{
		poorThing.attack("Loader");
		poorThing.takeDamage(2);
		poorThing.beRepaired(1);
		poorThing.takeDamage(2);
	}
	clone = poorThing;
	poorThing.attack("Loader");
	return (0);
}