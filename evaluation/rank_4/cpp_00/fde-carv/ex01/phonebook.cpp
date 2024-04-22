/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:52:43 by fde-carv          #+#    #+#             */
/*   Updated: 2024/02/03 15:32:05 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

/*
--> Constructor initializes the size and index of the phonebook.
*/
PhoneBook::PhoneBook() : _size(0), _index(0), _spaces(10) {}

PhoneBook::~PhoneBook(void) {}

/*
--> Adds a new contact to the phonebook.
  The `setInfo()` function is used to set the information of a new contact.
*/
void	PhoneBook::addContact()
{
	_contacts[_index].setInfo();
    if (_size > 7)
		std::cout << "\nContact added at memory position [" << _index << "] --> (oldest contact was overwritten)." << std::endl;
	else
		std::cout << "\nContact added at memory position [" << _index << "]" << std::endl;
	_index++;
	_size++;
	if (_index == 8)
		_index = 0;
    std::cout << "\nPress ENTER to continue." << std::endl;
	std::cin.ignore();
    std::cout << CLEAR;
	return ;    
}

/*
--> Searches for a contact in the phonebook.
  The `displaySearch()` function is used to display the contacts in a formatted manner.
  The `getInfo()` function is used to print out the information of a contact in a formatted manner.
*/
void	PhoneBook::searchContact()
{
	int			num;
	std::string	input;

    std::cout << CLEAR;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "|                  SEARCH CONTACTS                  |" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl << std::endl;

    displaySearch(this->_spaces);
    
	if (_size == 0)
	{
		std::cout << "\nNo contacts in phonebook\n";
        std::cout << "\nPress ENTER to continue." << std::endl;
	    std::cin.ignore();
        std::cout << CLEAR;
		return ;
	}
    
    std::cout  << std::endl;
    std::cout << "    Available commands are:" << std::endl;
    std::cout << std::endl;
	std::cout << "--> [index number]" << std::endl;
	std::cout << "--> BACK" << std::endl << std::endl;
    
	input = readInput("Please enter the index of the contact to search: ");
    
	while (1)
	{
		num = std::atoi(input.c_str());
		if (input == "BACK")
        {
            std::cout << CLEAR;
			break ;
        }
		if (input != "BACK")
		{
			if (input.empty() || !is_number(input) || (num < 0 || num > _size - 1 || num > 7))
			{
	 			std::cout << std::endl;
				std::cout << "\'" << input << "\' is not a valid input, please try again.\n";
				std::cout << "\nPress ENTER to continue." << std::endl;
				std::cin.ignore();
				searchContact();
				input = "BACK";
			}
			else
			{
				getContact(num).getInfo();
				std::cout << CLEAR;
				searchContact();
				break ;
			}
		}
	}
}

/*
--> Displays the contacts in a formatted manner.
  The `formatString()` function is used to format the string to be displayed.
*/
void	PhoneBook::displaySearch(int spacing)
{
	std::cout << "\n~~~~~~~~~~~~~~~~~~~~~Contact List~~~~~~~~~~~~~~~~~~~~\n\n";
	std::cout << std::setw(spacing) << "    |     INDEX|" ;
	std::cout << std::setw(spacing) << "      NAME|";
	std::cout << std::setw(spacing) << " LAST NAME|";
	std::cout << std::setw(spacing) << " NICK NAME|";
	std::cout << "\n";
	std::cout << "    |~~~~~~~~~~|~~~~~~~~~~|~~~~~~~~~~|~~~~~~~~~~|" << std::endl;
	
    for (int i = 0; (i < _size && i < 8); i++)
	{
		std::cout << "    |" << std::setw(spacing - 2) << "[" << i << "]|";
		std::cout << std::setw(spacing) << formatString(getContact(i).getFirstName()) << "|";
		std::cout << std::setw(spacing) << formatString(getContact(i).getLastName()) << "|";
		std::cout << std::setw(spacing) << formatString(getContact(i).getNickName()) << "|";
		std::cout << "\n";
	}
	
	std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}
"EXIT" && input != "ADD" && input != "SEARCH
/*
--> Initializes the phonebook, and sets the menu and the available commands.
*/
void	PhoneBook::initPhone()
{
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "|                   PHONEBOOK APP                   |" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl << std::endl;
	std::cout << "    Available commands are:" << std::endl;
    std::cout << "\n--> ADD" << std::endl;
	std::cout << "--> SEARCH" << std::endl;
	std::cout << "--> EXIT" << std::endl << std::endl;
}

/*
--> Returns the contact at the specified index.
*/
Contact	PhoneBook::getContact(int index)
{
	return (_contacts[index]);
}


