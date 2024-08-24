/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:56:59 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/20 17:53:25 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{}

AMateria::AMateria(std::string const &type) : type(type) {}

AMateria::~AMateria() {}

AMateria::AMateria(AMateria& obj) : type(obj.getType()) {}

AMateria& AMateria::operator=(const AMateria& obj)
{
	this->type = obj.getType();
	return (*this);
}

std::string const &AMateria::getType() const // Returns the materia type
{
	return (this->type);
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "* punches " << target.getName() << " *\n";
}