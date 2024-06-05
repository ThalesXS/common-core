/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:28:15 by txisto-d          #+#    #+#             */
/*   Updated: 2024/06/05 18:46:52 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Standard Brain constructor\n";
}

Brain::~Brain(void)
{
	std::cout << "A Brain has been destroyed\n";

}

Brain::Brain(Brain& obj)
{
	int i = -1;
	while (++i < 100)
		this->ideas[i] = obj.ideas[i];
	std::cout << "Copy Brain constructor\n";
}

Brain& Brain::operator=(Brain& obj)
{
	int i = -1;
	while (++i < 100)
		this->ideas[i] = obj.ideas[i];
	std::cout << "Brain Assignment operator\n";
	return (*this);
}

void	Brain::setIdea(std::string idea, unsigned int num)
{
	this->ideas[num] = idea;
}

std::string	Brain::getIdea(unsigned int num)
{
	return (this->ideas[num]);
}