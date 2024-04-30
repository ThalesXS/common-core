/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:54:06 by txisto-d          #+#    #+#             */
/*   Updated: 2024/04/30 23:04:29 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string human, Weapon& weapon)
		: name(human), equipment(weapon)
{
}

void	HumanA::attack(void)
{
	std::cout << name << " attacks with their " << equipment.getType();
	std::cout << std::endl;
}