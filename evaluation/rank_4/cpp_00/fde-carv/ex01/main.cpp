/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:45:15 by fde-carv          #+#    #+#             */
/*   Updated: 2024/02/02 15:12:24 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

/*
--> Reads the input from the user.
  The `formatString()` function is used to format the input.
*/
int	main(void)
{
	std::string	input;
	PhoneBook	phonebook;
    std::cout << CLEAR;
	while (1)
	{
        phonebook.initPhone();
        input = readInput("Please enter a command: ");
		if (input == "EXIT")
		{
			std::cout << "\nExiting the Phonebook APP.\n";
			break ;
		}
		if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
			phonebook.searchContact();
		else if (input != "EXIT" && input != "ADD" && input != "SEARCH")
        {
			std::cout << "\nError: Invalid command, please try again\n";
            std::cout << "\nPress ENTER to continue." << std::endl;
	        std::cin.ignore();
            std::cout << CLEAR;
        }
	}
	return (0);
}
