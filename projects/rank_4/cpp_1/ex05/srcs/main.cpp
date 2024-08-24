/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:30:05 by txisto-d          #+#    #+#             */
/*   Updated: 2024/08/24 04:18:43 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl		myHarl;
	std::string	command;

	if (argc != 2)
		std::cout << "Try only one of the following: \"DEBUG\", \"INFO\", \"WARNING\", \"ERROR\"\n";
	else 
	{
		command = argv[1];
		myHarl.complain(command);
	}
	return (0);
}