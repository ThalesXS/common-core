/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:31:01 by txisto-d          #+#    #+#             */
/*   Updated: 2024/08/24 09:59:54 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "The gatekeeper showed himself! Welcome " << this->name << "." <<std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout <<"The Gatekeeper " << this->name << " exploded." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap& SC4V_TP) : ClapTrap(SC4V_TP)
{
	this->name = SC4V_TP.name;
    this->attackDamage = SC4V_TP.attackDamage;
    this->hitPoints = SC4V_TP.hitPoints;
    this->energyPoints = SC4V_TP.energyPoints;
    std::cout <<"Wow, " << SC4V_TP.name << " just multiplied itself!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& SC4V_TP)
{
	std::cout << this->name << " decided to become " << SC4V_TP.name << "." << std::endl;
    this->name = SC4V_TP.name;
    this->attackDamage = SC4V_TP.attackDamage;
    this->hitPoints = SC4V_TP.hitPoints;
    this->energyPoints = SC4V_TP.energyPoints;
    return (*this);
}


void    ScavTrap::guardGate()
{
    if (this->hitPoints > 0 && this->energyPoints > 0)
	    std::cout << this->name << " entered Gate Keeper mode." << std::endl;
    else if (this->hitPoints > 0)
        std::cout << this->name << "is too tired to change modes." << std::endl;
    else
        std::cout << this->name << " can't do anything, he is dead..." << std::endl;
}
