/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:03:41 by txisto-d          #+#    #+#             */
/*   Updated: 2024/08/24 10:49:17 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(std::string animal)
{
	this->type = animal;
	std::cout << "Standard WRONG ANIMAL constructor" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "The WRONG ANIMAL " << this->type << " just died.\n";
}

WrongAnimal::WrongAnimal(WrongAnimal& obj)
{
	this->type = obj.type;
	std::cout << "Copy WRONG ANIMAL constructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
	this->type = obj.type;
	std::cout << "Assignment WRONG ANIMAL operator" << std::endl;
	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout << this->type << ": HDHAAWOWEASDCAW.\n";
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}