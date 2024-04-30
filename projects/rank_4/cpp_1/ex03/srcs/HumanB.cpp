/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:54:14 by txisto-d          #+#    #+#             */
/*   Updated: 2024/04/30 22:33:31 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string human)
{
	name = human;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	equipment = &weapon;
}

void	HumanB::attack(void)
{
	std::cout << name << " attacks with their " << (*equipment).getType();
	std::cout << std::endl;
}