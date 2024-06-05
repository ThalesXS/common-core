/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:53:58 by txisto-d          #+#    #+#             */
/*   Updated: 2024/05/21 13:29:33 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    std::cout << "A new ClapTrap has been born! Welcome " << this->name << "." <<std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->name << " exploded." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& CL4P_TP)
{
    this->name = CL4P_TP.name;
    this->attackDamage = CL4P_TP.attackDamage;
    this->hitPoints = CL4P_TP.hitPoints;
    this->energyPoints = CL4P_TP.energyPoints;
    std::cout <<"Wow, " << CL4P_TP.name << " just multiplied itself!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& CL4P_TP)
{
    std::cout << this->name << " decided to become " << CL4P_TP.name << "." << std::endl;
    this->name = CL4P_TP.name;
    this->attackDamage = CL4P_TP.attackDamage;
    this->hitPoints = CL4P_TP.hitPoints;
    this->energyPoints = CL4P_TP.energyPoints;
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if (this->hitPoints > 0 && this->energyPoints > 0)
    {
        this->energyPoints -= 1;
    std::cout << this->name << " attacks " << target << ", causing " \
        << this->attackDamage << " damage!" << std::endl;
    }
    else if (this->hitPoints > 0)
        std::cout << this->name << " is too tired." << std::endl;
    else
        std::cout << this->name << " can't do anything, he is dead..." << std::endl;
}

void ClapTrap::takeDamage(int amount)
{
    if (this->hitPoints > 0)
    {
        this->hitPoints -= amount;
        std::cout << this->name << " suffers " << amount << " damage, " \
            << "his HP is " << this->hitPoints << " now." << std::endl;
    }
    else
        std::cout << this->name << " is about to die, stop beating him!" << std::endl;
}

void ClapTrap::beRepaired(int amount)
{
    if (this->hitPoints > 0 && this->energyPoints > 0)
    {
        this->hitPoints += amount;
        this->energyPoints -= 1;
        std::cout << this->name << " spends 1 EP recover " << amount << " HP, " \
        << "his HP is " << this->hitPoints << " now." << std::endl;
    }
    else if (this->hitPoints > 0)
        std::cout << this->name << " is too tired." << std::endl;
    else
        std::cout << this->name << " can't do anything, he is dead..." << std::endl;
}

void    ClapTrap::setAttribute(int value, clapAtt att)
{
    switch (att)
    {
    case HP:
        this->hitPoints = value;
        break;
    case EP:
        this->energyPoints = value;
        break;
    case ATK:
        this->attackDamage = value;
        break;
    default:
        break;
    }
}

int    ClapTrap::getAttribute(clapAtt att)
{
    int value;

    switch (att)
    {
    case HP:
        value = this->hitPoints;
        break;
    case EP:
        value = this->energyPoints;
        break;
    case ATK:
        value = this->attackDamage;
        break;
    default:
        value = 0;
        break;
    }
    return (value);
}
