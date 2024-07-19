/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:34:54 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/19 17:39:39 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	this->type = "cure";
}

Cure::~Cure() {};

Cure::Cure(Cure& obj) : AMateria(obj.getType())
{
	this->type = obj.getType();
}

Cure& Cure::operator=(const Cure& obj)
{
	this->type = obj.getType();
}

Cure* Cure::clone() const
{
	return (new Cure());
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() <<"'s wounds *\n";
}
