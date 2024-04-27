/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:15:22 by txisto-d          #+#    #+#             */
/*   Updated: 2024/04/27 11:00:34 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	string	contactInfo;

	contactIndex = 0;
	displayBook();
	std::cout << "Enter a command: ";
	std::cin >> std::setw(3) >> contactInfo;
	std::cout << contactInfo;
}

void	PhoneBook::displayBook(void)
{
	system("clear");
	std::cout << PROMPT_0 << PROMPT_1 << PROMPT_2 << PROMPT_3 << PROMPT_4;
	std::cout << "│   │    Name    │   Number    │\n";
	std::cout << END_PROM;
	while (contactIndex < 8)
	{
		std::cout << "│ " << contactIndex + 1 << " │   Antônio  │ 123 456 789 │\n";
		if (contactIndex != 7)
			std::cout << END_PROM;
		contactIndex++;
	}
	std::cout << END_CONT << COMMANDS << END_COMA;
}