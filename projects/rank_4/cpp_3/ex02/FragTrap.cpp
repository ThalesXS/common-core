/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:44:00 by txisto-d          #+#    #+#             */
/*   Updated: 2024/08/24 10:02:33 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "Everyone, say hey to the new ninja, " << this->name << "." <<std::endl;
}

FragTrap::~FragTrap()
{
	std::cout <<"FragTrap, a ninja robot called " << this->name << " exploded." << std::endl;
}

FragTrap::FragTrap(FragTrap& FR4G_TP) : ClapTrap(FR4G_TP)
{
	this->name = FR4G_TP.name;
    this->attackDamage = FR4G_TP.attackDamage;
    this->hitPoints = FR4G_TP.hitPoints;
    this->energyPoints = FR4G_TP.energyPoints;
    std::cout <<"Wow, " << FR4G_TP.name << " just multiplied itself!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& FR4G_TP)
{
	std::cout << this->name << " decided to become " << FR4G_TP.name << "." << std::endl;
    this->name = FR4G_TP.name;
    this->attackDamage = FR4G_TP.attackDamage;
    this->hitPoints = FR4G_TP.hitPoints;
    this->energyPoints = FR4G_TP.energyPoints;
    return (*this);
}


void    FragTrap::highFivesGuys(void)
{
    if (this->hitPoints > 0 && this->energyPoints > 0)
	    std::cout << this->name << ": GIMME FIVE!" << std::endl;
    else if (this->hitPoints > 0)
        std::cout << this->name << "is too tired to ask for a high five :(" << std::endl;
    else
        std::cout << this->name << " can't do anything, he is dead..." << std::endl;
}
