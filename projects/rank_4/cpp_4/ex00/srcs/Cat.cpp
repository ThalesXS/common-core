/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:21:37 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/18 12:22:14 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	this->type = "Cat";
	std::cout << "Standard CAT constructor\n";
}

Cat::~Cat()
{
	std::cout << "The CAT just died.\n";
}

Cat::Cat(Cat& obj) : Animal(obj)
{
	this->type = obj.type;
	std::cout << "Copy CAT constructor\n";
}

Cat& Cat::operator=(const Cat& obj)
{
	this->type = obj.type;
	std::cout << "Assignment CAT operator\n";
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << this->type << ": meow meow.\n";
}
