/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:03:57 by txisto-d          #+#    #+#             */
/*   Updated: 2024/06/05 18:17:30 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	this->type = "Wrong Cat";
	std::cout << "Standard WRONG CAT constructor\n";
}

WrongCat::~WrongCat()
{
	std::cout << "The WRONG CAT just died.\n";
}

WrongCat::WrongCat(WrongCat& obj)
{
	this->type = obj.type;
	std::cout << "Copy WRONG CAT constructor\n";
}

WrongCat& WrongCat::operator=(const WrongCat& obj)
{
	this->type = obj.type;
	std::cout << "Assignment WRONG CAT operator\n";
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << this->type << ": WHAT DOES THE FOX SAY???.\n";
}
