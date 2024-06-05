/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:45:02 by txisto-d          #+#    #+#             */
/*   Updated: 2024/05/21 13:49:06 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ScavTrap poorThing;
	FragTrap ninja;
	poorThing.attack("Loader");
	ninja.attack("Loader");
	poorThing.guardGate();
	ninja.highFivesGuys();
	return (0);
}