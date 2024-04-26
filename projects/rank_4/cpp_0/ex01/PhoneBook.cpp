/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:15:22 by txisto-d          #+#    #+#             */
/*   Updated: 2024/04/26 21:28:33 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	string	contactInfo;

	displayBook();
	std::cout << "│   ADD   │  SEARCH  │  EXIT   │\n";
	std::cout << DIVIDER;
	std::cin >> contactInfo;
	std::cout << contactInfo;
}

void	PhoneBook::displayBook(void)
{
	system("clear");
	std::cout << PROMPT_0 << PROMPT_1 << PROMPT_2 << PROMPT_3 << PROMPT_4;
}