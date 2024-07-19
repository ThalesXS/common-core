/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:35:11 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/19 17:39:36 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("Ice")
{
	this->type = "Ice";
}

Ice::~Ice() {};

Ice::Ice(Ice& obj) : AMateria(obj.getType())
{
	this->type = obj.getType();
}

Ice& Ice::operator=(const Ice& obj)
{
	this->type = obj.getType();
}

Ice* Ice::clone() const
{
	return (new Ice());
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() <<" *\n";
}
