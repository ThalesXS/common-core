/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:21:55 by txisto-d          #+#    #+#             */
/*   Updated: 2024/06/05 18:48:23 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	this->type = "Dog";
	std::cout << "Standard DOG constructor\n";
	this->brain = new Brain();
}

Dog::~Dog(void)
{
	delete (this->brain);
	std::cout << "The DOG just died.\n";
}

Dog::Dog(Dog& obj) : Animal()
{
	this->type = obj.type;
	this->brain = obj.brain;
	std::cout << "Copy DOG constructor\n";
}

Dog& Dog::operator=(const Dog& obj)
{
	this->type = obj.type;
	this->brain = obj.brain;
	std::cout << "Assignment DOG operator\n";
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << this->type << ": woof woof.\n";
}

void	Dog::setIdeaInBrain(std::string idea, unsigned int num)
{
	this->brain->setIdea(idea, num);
}

std::string	Dog::getIdeaFromBrain(unsigned int num)
{
	return (this->brain->getIdea(num));
}