/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:30:30 by txisto-d          #+#    #+#             */
/*   Updated: 2024/05/02 11:28:01 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::complain(std::string level)
{
	int			i;
	std::string	commands[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	getComplain	list[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	i = 0;
	while (i < 4)
	{
		if (level == commands[i])
		{
			(this->*list[i])();
			break;
		}
		i++;
	}
	if (i == 4)
		std::cout << "Invalid Command\n";
}

void	Harl::debug(void)
{
	std::cout << "[DEBUG]: We are debuging here...\n";
}

void	Harl::info(void)
{
	std::cout << "[INFO]:When you call Harl it works somehow.\n";
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]:STD stands for \"\e[3mstandard\e[0m\"\n";
}

void	Harl::error(void)
{
	std::cout << "[ERROR]: and unrecoverable error has ocurred, please don't cry.\n";
}