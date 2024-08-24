/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:43:49 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/23 16:15:22 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name) : name(name)
{
	this->items = 0;
	this->inventory[0] = NULL;
	this->inventory[1] = NULL;
	this->inventory[2] = NULL;
	this->inventory[3] = NULL;
	trashAmount = 0;
}

Character::~Character()
{
	int	i = 0;
	while (this->items)
	{
		this->unequip(0);
	}
	while (i < this->trashAmount)
		delete this->floor[i++];
}

Character::Character(Character& obj) : name(obj.getName())
{
	int i = -1;
	
	this->items = obj.getItems();
	while (++i < this->items)
		this->inventory[i] = obj.getInventory(i);
}

Character& Character::operator=(Character& obj)
{
	int i = -1;
	
	this->name = obj.getName();
	this->items = obj.getItems();
	while (++i < this->items)
		this->inventory[i] = obj.getInventory(i);
	return (*this);
}

std::string const &	Character::getName() const
{
	return (this->name);
}

void	Character::equip(AMateria* m)
{
	if (!m)
		return ;
	if (this->items < 4)
	{
		this->inventory[this->items] = m;
		this->items++;
	}
	else
	{
		std::cout << "Inventory is full.\n";
		this->addToFloor(m);
	}
}

void	Character::unequip(int idx)
{
	this->addToFloor(this->inventory[idx]);
	while (idx < 3 && idx >= 0)
	{
		this->inventory[idx] = this->inventory[idx + 1];
		idx++;
	}
	if (idx == 3)
	{
		this->inventory[idx] = NULL;
		this->items--;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < this->items && idx >=0)
		this->inventory[idx]->use(target);
	else
		std::cout << "No Materia available in this index\n";
}
int		Character::getItems() const
{
	return (this->items);
}

AMateria*	Character::getInventory(int index) const
{
	if (index < this->items && index >=0)
		return (this->inventory[index]);
	else
		return (NULL);
}

AMateria**	Character::getFloor()
{
	return (this->floor);
}

void	Character::addToFloor(AMateria* materia)
{
	int i = 0;
	if (trashAmount == 50)
	{
		delete this->floor[i];
		while (i < 49)
		{
			this->floor[i] = this->floor[i + 1];
			i++;
		}
		this->floor[trashAmount] = materia;
		return ;
	}
	this->floor[trashAmount] = materia;
	this->trashAmount++;
}