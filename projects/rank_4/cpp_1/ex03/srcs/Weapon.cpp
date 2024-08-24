/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:54:18 by txisto-d          #+#    #+#             */
/*   Updated: 2024/08/24 03:47:17 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
	type = name;
}

void	Weapon::setType(std::string name)
{
	type = name;
}

const std::string& Weapon::getType(void)
{
	return (type);
}