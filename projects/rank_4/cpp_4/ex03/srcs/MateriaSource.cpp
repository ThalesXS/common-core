/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:00:46 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/20 17:57:34 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <cstring>
#include <string>
MateriaSource::MateriaSource()
{
	this->materias = 0;
	this->pages[0] = NULL;
	this->pages[1] = NULL;
	this->pages[2] = NULL;
	this->pages[3] = NULL;
}

MateriaSource::~MateriaSource()
{
	while (this->materias >= 0)
	{
		delete (this->pages[materias]);
		this->materias--;
	}
}

MateriaSource::MateriaSource(MateriaSource& obj)
{
	int	i = -1;
	
	this->materias = obj.getMaterias();
	while (++i < this->materias)
		this->pages[i] = obj.getPages(i);
}
MateriaSource&	MateriaSource::operator=(MateriaSource& obj)
{
	int	i = -1;
	
	this->materias = obj.getMaterias();
	while (++i < this->materias)
		this->pages[i] = obj.getPages(i);
	return (*this);
}
void	MateriaSource::learnMateria(AMateria* materia)
{
	if (this->materias < 4)
	{
		this->pages[this->materias] = materia;
		this->materias++;
	}
	else
		std::cout << "SpellBook is full.\n";
}
AMateria*	MateriaSource::createMateria(std::string const & type)
{
	int	i = -1;

	while (++i < this->materias)
	{
		if (!strcmp(this->pages[i]->getType().c_str(), type.c_str()))
			return (this->pages[i]->clone());
	}
	std::cout << "Materia not found!\n" << i << std::endl;
	return (NULL);
}

int	MateriaSource::getMaterias()
{
	return (this->materias);
}

AMateria*	MateriaSource::getPages(int index)
{
	if (index < this->materias && index >= 0)
		return (this->pages[index]);
	return (NULL);
}
