/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:15:22 by txisto-d          #+#    #+#             */
/*   Updated: 2024/04/27 23:58:42 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	contactIndex = 0;
	error = 0;
	while (1)
	{
		displayIntro();
	}
}

void	PhoneBook::displayIntro(void)
{
	string	command;

	system("clear");
	std::cout << TOP << PROMPT_1 << PROMPT_2 << PROMPT_3 << MIDDLE << WALL;
	std::cout << "│         Welcome to the PhoneBook!         │\n";
	std::cout << WALL;
	std::cout << "│ ┌───────────────────────────────────────┐ │\n";
	std::cout << "│ │  Please enter one of the following.   │ │\n";
	std::cout << "│ ├────────┬──────────────────────────────┤ │\n";
	std::cout << "│ │  ADD   │ Add a new contact to the list│ │\n";
	std::cout << "│ ├────────┼──────────────────────────────┤ │\n";
	std::cout << "│ │ SEARCH │ Display the list of contacts │ │\n";
	std::cout << "│ ├────────┼──────────────────────────────┤ │\n";
	std::cout << "│ │  EXIT  │ Exit the PhoneBook           │ │\n";
	std::cout << "│ └────────┴──────────────────────────────┘ │\n";
	std::cout << WALL ;
	std::cout << BOTTOM;
	printError();
	std::cout << "Please enter a command: ";
	getline(std::cin, command);
	if (command == "ADD")
		addContact();
	else if (command == "SEARCH")
		displayList();
	else if (command == "EXIT")
		exit(0);
	else
		error = INVALCOMMAND;
}

void	PhoneBook::displayList(void)
{
	int	i;
	string	command;
	string	temp;

	i = 0;
	system("clear");
	std::cout << TOP << PROMPT_1 << PROMPT_2 << PROMPT_3 << START_LIST;
	std::cout << "│  Index   │   Name   │ Sur-name │ Nickname │\n";
	std::cout << MID_LIST;
	while (i < 8)
	{
		std::cout << "│" << std::setw(10) << std::right <<  i + 1;
		temp = contactBook[i].getAttribute(FIRSTNAME);
		if (temp.length() > 10)
			temp = temp.substr(0, 9) + ".";
		std::cout << "│" << std::setw(10) << std::right << temp;
		temp = contactBook[i].getAttribute(LASTNAME);
		if (temp.length() > 10)
			temp = temp.substr(0, 9) + ".";
		std::cout << "│" << std::setw(10) << std::right << temp;
		temp = contactBook[i].getAttribute(NICKNAME);
		if (temp.length() > 10)
			temp = temp.substr(0, 9) + ".";
		std::cout << "│" << std::setw(10) << std::right << temp << "│" << std::endl;
		if (i != 7)
			std::cout << MID_LIST;
		i++;
	}
	std::cout << MIDDLE;
	std::cout << "│ ┌───────────────────────────────────────┐ │\n";
	std::cout << "│ │ Please enter the index of the contact │ │\n";
	std::cout << "│ │ you would like to display, or 0 to    │ │\n";
	std::cout << "│ │ return to the main menu.              │ │\n";
	std::cout << "│ └───────────────────────────────────────┘ │\n";
	std::cout << BOTTOM;
	std::cout << "Please enter a command: ";
	getline(std::cin, command);
	if (command == "0")
		return ;
	else if (command == "1" || command == "2" || command == "3" || command == "4" || command == "5" || command == "6" || command == "7" || command == "8")
	{
		if (contactBook[command[0] - '0' - 1].getAttribute(FIRSTNAME) != "")
			displayContact(command[0] - '0' - 1);
		else
			displayEmpty();
	}
	displayList();
}

void	PhoneBook::displayContact(int index)
{
	string name;

	system("clear");
	std::cout << TOP << PROMPT_1 << PROMPT_2 << PROMPT_3 << MIDDLE;
	std::cout << WALL << "│ First Name: ";
	printFullArgument(contactBook[index].getAttribute(FIRSTNAME), 29);
	std::cout << WALL << "│ Last Name: ";
	printFullArgument(contactBook[index].getAttribute(LASTNAME), 30);
	std::cout << WALL << "│ Nickname: ";
	printFullArgument(contactBook[index].getAttribute(NICKNAME), 31);
	std::cout << WALL << "│ Phone Number: ";
	printFullArgument(contactBook[index].getAttribute(PHONENUMBER), 27);
	std::cout << WALL << "│ Darkest Secret: ";
	printFullArgument(contactBook[index].getAttribute(DARKESTSECRET), 25);
	std::cout << WALL << WALL << WALL;
	std::cout << MIDDLE;
	std::cout << "│ ┌───────────────────────────────────────┐ │\n";
	std::cout << "│ │    Enter 0 to return to the list.     │ │\n";
	std::cout << "│ └───────────────────────────────────────┘ │\n";
	std::cout << BOTTOM;
	std::cout << "Please enter a command: ";
	std::cin >> name;
	if (name == "0")
		return ;
	else
		displayContact(index);
}

void	PhoneBook::addContact(void)
{
	string	str;

	system("clear");
	std::cout << TOP << PROMPT_1 << PROMPT_2 << PROMPT_3 << MIDDLE;
	std::cout <<"│  Please enter the following information:  │\n";
	std::cout << BOTTOM;
	std::cout << "First Name: ";
	getline(std::cin, str);
	contactBook[contactIndex].setAttribute(str, FIRSTNAME);
	std::cout << "Last Name: ";
	getline(std::cin, str);
	contactBook[contactIndex].setAttribute(str, LASTNAME);
	std::cout << "Nickname: ";
	getline(std::cin, str);
	contactBook[contactIndex].setAttribute(str, NICKNAME);
	std::cout << "Phone Number: ";
	getline(std::cin, str);
	contactBook[contactIndex].setAttribute(str, PHONENUMBER);
	std::cout << "Darkest Secret: ";
	getline(std::cin, str);
	contactBook[contactIndex].setAttribute(str, DARKESTSECRET);
	mustFlush();
	if (contactIndex == 8)
		contactIndex = 0;
}

void	PhoneBook::mustFlush(void)
{
	if (contactBook[contactIndex].getAttribute(FIRSTNAME) == "")
		flushContact(FIRSTNAME);
	else if(contactBook[contactIndex].getAttribute(LASTNAME) == "")
		flushContact(LASTNAME);
	else if(contactBook[contactIndex].getAttribute(NICKNAME) == "")
		flushContact(NICKNAME);
	else if(contactBook[contactIndex].getAttribute(PHONENUMBER) == "")
		flushContact(PHONENUMBER);
	else if(contactBook[contactIndex].getAttribute(DARKESTSECRET) == "")
		flushContact(DARKESTSECRET);
	else if (wrongNumber())
		flushContact(INVALNUMBER);
	else
		contactIndex++;
}

void	PhoneBook::flushContact(int err)
{
	error = err;
	contactBook[contactIndex].setAttribute("", FIRSTNAME);
	contactBook[contactIndex].setAttribute("", LASTNAME);
	contactBook[contactIndex].setAttribute("", NICKNAME);
	contactBook[contactIndex].setAttribute("", PHONENUMBER);
	contactBook[contactIndex].setAttribute("", DARKESTSECRET);
}

int	PhoneBook::wrongNumber(void)
{
	int	i;
	string number;

	i = 0;
	number = contactBook[contactIndex].getAttribute(PHONENUMBER);
	while (number[i])
	{
		if (!isdigit(number[i]))
			return (1);
		i++;
	}
	return (0);
}

void	PhoneBook::printError(void)
{
	switch (error)
	{
	case FIRSTNAME:
		std::cout << "Error: First Name cannot be empty.\n\n";
		break;
	case LASTNAME:
		std::cout << "Error: Last Name cannot be empty.\n\n";
		break;
	case NICKNAME:
		std::cout << "Error: Nickname cannot be empty.\n\n";
		break;
	case PHONENUMBER:
		std::cout << "Error: Phone Number cannot be empty.\n\n";
		break;
	case DARKESTSECRET:
		std::cout << "Error: Darkest Secret cannot be empty.\n\n";
		break;
	case INVALNUMBER:
		std::cout << "Error: Phone Number must be numeric only.\n\n";
		break;
	case INVALCOMMAND:
		std::cout << "Error: Invalid command.\n\n";
		break;
	default:
		break;
	}
	error = 0;
}

void	PhoneBook::displayEmpty(void)
{
	string	command;
	system("clear");
	std::cout << TOP << PROMPT_1 << PROMPT_2 << PROMPT_3 << MIDDLE;
	std::cout << WALL << WALL << "│  This contact is empty. Please add some   │\n";
	std::cout << "│  information to display it.               │\n" << WALL;
	std::cout << WALL << WALL << "│ TIP: Use the ADD command to add a new     │\n";
	std::cout << "│      contact.                             │\n";
	std::cout << WALL << WALL << "│ TIP 2: Try to make some friends.          │\n";
	std::cout << WALL;
	std::cout << MIDDLE;
	std::cout << "│ ┌───────────────────────────────────────┐ │\n";
	std::cout << "│ │    Enter 0 to return to the list.     │ │\n";
	std::cout << "│ └───────────────────────────────────────┘ │\n";
	std::cout << BOTTOM;
	std::cout << "Please enter a command: ";
	getline(std::cin, command);
	if (command == "0")
		return ;
	else
		displayEmpty();
}

void	PhoneBook::printFullArgument(string str, long unsigned int size)
{
	string	temp;
	
	if (str.length() > size)
	{
		temp = str.substr(size, str.length() - size);
		while (str.length() > size)
		{
			std::cout << str.substr(0, size) << " │\n";
			std::cout << "│" << std::setw(42 - size) << std::left << " ";
			str = temp;
			if (str.length() > size)
				temp = str.substr(size, str.length() - size - 1);
		}
		std::cout << std::setw(size) << std::left << str.substr(0, size) << " │\n";
	}
	else
		std::cout << std::setw(size) << std::left <<  str << " │\n";
}