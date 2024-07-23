/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:02:33 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/23 16:20:58 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"

Floor::Floor()
{
	this->amount = 0;
	this->droppedItems = NULL;
}

Floor::~Floor()
{
	int	i = 0;

	if (this->droppedItems)
	{
		while (this->droppedItems[i])
		{
			delete (this->droppedItems[i]);
			i++;
		}
		delete [](this->droppedItems);
	}
}

Floor::Floor(Floor& obj)
{
	this->setDroppedItems(obj.getDroppedItems());
}

Floor&	Floor::operator=(Floor& obj)
{
	this->setDroppedItems(obj.getDroppedItems());
	return (*this);
}

AMateria**	Floor::getDroppedItems()
{
	return (this->droppedItems);
}

int	Floor::length()
{
	return (this->amount);
}

void	Floor::setDroppedItems(AMateria** items)
{
	int	i = 0;

	if (this->droppedItems)
	{
		while (this->droppedItems[i])
		{
			delete (this->droppedItems[i]);
			i++;
		}
		i = 0;
		delete [](this->droppedItems);
	}
	this->droppedItems = items;
	while (this->droppedItems[i])
		i++;
	this->amount = i;
}

void	Floor::push(AMateria* materia)
{
	AMateria**	temp;
	int			i;

	i = 0;
	temp = new AMateria*[this->amount + 1];
	while (i < this->amount)
	{
		temp[i] = this->droppedItems[i];
		i++;
	}
	temp[i] = materia;
	this->amount++;
	delete [](this->droppedItems);
	this->droppedItems = temp;
}

void	Floor::erase()
{
	int	i = 0;

	if (this->droppedItems)
	{
		while (this->droppedItems[i])
		{
			delete (this->droppedItems[i]);
			i++;
		}
		delete [](this->droppedItems);
		this->droppedItems = NULL;
	}
}