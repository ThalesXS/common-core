/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:30:05 by txisto-d          #+#    #+#             */
/*   Updated: 2024/05/02 10:54:07 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl		myHarl;
	std::string	command;

	if (argc != 2)
		std::cout << "message\n";
	else 
	{
		command = argv[1];
		myHarl.complain(command);
	}
	return (0);
}