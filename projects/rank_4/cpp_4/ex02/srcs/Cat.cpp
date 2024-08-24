/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:21:37 by txisto-d          #+#    #+#             */
/*   Updated: 2024/06/05 18:48:17 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	this->type = "Cat";
	std::cout << "Standard CAT constructor\n";
	this->brain = new Brain();
}

Cat::~Cat()
{
	delete (this->brain);
	std::cout << "The CAT just died.\n";
}

Cat::Cat(Cat& obj) : Animal()
{
	this->type = obj.type;
	this->brain = obj.brain;
	std::cout << "Copy CAT constructor\n";
}

Cat& Cat::operator=(const Cat& obj)
{
	this->type = obj.type;
	this->brain = obj.brain;
	std::cout << "Assignment CAT operator\n";
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << this->type << ": meow meow.\n";
}

void	Cat::setIdeaInBrain(std::string idea, unsigned int num)
{
	this->brain->setIdea(idea, num);
}

std::string	Cat::getIdeaFromBrain(unsigned int num) const
{
	return (this->brain->getIdea(num));
}