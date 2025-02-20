/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:21:55 by txisto-d          #+#    #+#             */
/*   Updated: 2024/06/05 17:58:21 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	this->type = "Dog";
	std::cout << "Standard DOG constructor\n";
}

Dog::~Dog(void)
{
	std::cout << "The DOG just died.\n";
}

Dog::Dog(Dog& obj) : Animal()
{
	this->type = obj.type;
	std::cout << "Copy DOG constructor\n";
}

Dog& Dog::operator=(const Dog& obj)
{
	this->type = obj.type;
	std::cout << "Assignment DOG operator\n";
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << this->type << ": woof woof.\n";
}
