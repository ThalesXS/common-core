/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:13:28 by txisto-d          #+#    #+#             */
/*   Updated: 2024/06/05 17:57:06 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(std::string animal)
{
	this->type = animal;
	std::cout << "Standard ANIMAL constructor" << std::endl;
}

Animal::~Animal()
{
	std::cout << "The ANIMAL " << this->type << " just died.\n";
}

Animal::Animal(Animal& obj)
{
	this->type = obj.type;
	std::cout << "Copy ANIMAL constructor" << std::endl;
}

Animal& Animal::operator=(const Animal& obj)
{
	this->type = obj.type;
	std::cout << "Assignment ANIMAL operator" << std::endl;
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << this->type << " made a sound.\n";
}

std::string	Animal::getType(void) const
{
	return (this->type);
}