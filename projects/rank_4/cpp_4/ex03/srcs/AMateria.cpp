/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:56:59 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/19 16:40:17 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type = "") : type(type) {}

AMateria::~AMateria() {}

AMateria::AMateria(AMateria& obj) : type(obj.getType()) {}

AMateria& AMateria::operator=(const AMateria& obj)
{
	this->type = obj.getType();
}

std::string const &AMateria::getType() const // Returns the materia type
{
	return (this->type);
}