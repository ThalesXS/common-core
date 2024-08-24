/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:15:22 by txisto-d          #+#    #+#             */
/*   Updated: 2024/08/24 02:19:10 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	contactIndex = 0;
	error = 0;
	std::wstring command = L"a";
	displayIntro();
}

void	PhoneBook::displayIntro(void)
{
	std::wstring	command;

	system("clear");
	std::wcout << TOP << PROMPT_1 << PROMPT_2 << PROMPT_3 << MIDDLE << WALL;
	std::wcout << L"│         Welcome to the PhoneBook!         │\n";
	std::wcout << WALL;
	std::wcout << L"│ ┌───────────────────────────────────────┐ │\n";
	std::wcout << L"│ │  Please enter one of the following.   │ │\n";
	std::wcout << L"│ ├────────┬──────────────────────────────┤ │\n";
	std::wcout << L"│ │  ADD   │ Add a new contact to the list│ │\n";
	std::wcout << L"│ ├────────┼──────────────────────────────┤ │\n";
	std::wcout << L"│ │ SEARCH │ Display the list of contacts │ │\n";
	std::wcout << L"│ ├────────┼──────────────────────────────┤ │\n";
	std::wcout << L"│ │  EXIT  │ Exit the PhoneBook           │ │\n";
	std::wcout << L"│ └────────┴──────────────────────────────┘ │\n";
	std::wcout << WALL ;
	std::wcout << BOTTOM;
	printError();
	std::wcout << L"Please enter a command: ";
	if (!getline(std::wcin, command))
		exit(0);
	if (command == L"ADD")
		addContact();
	else if (command == L"SEARCH")
		displayList();
	else if (command == L"EXIT")
		exit(0);
	else
		error = INVALCOMMAND;
	displayIntro();
}

void	PhoneBook::displayList(void)
{
	int	i;
	std::wstring	command;
	std::wstring	temp;

	i = 0;
	system("clear");
	std::wcout << TOP << PROMPT_1 << PROMPT_2 << PROMPT_3 << START_LIST;
	std::wcout << L"│  Index   │   Name   │ Sur-name │ Nickname │\n";
	std::wcout << MID_LIST;
	while (i < 8)
	{
		std::wcout << L"│" << std::setw(10) << std::right <<  i + 1;
		temp = contactBook[i].getAttribute(FIRSTNAME);
		if (temp.length() > 10)
			temp = temp.substr(0, 9) + L".";
		std::wcout << L"│" << std::setw(10) << std::right << temp;
		temp = contactBook[i].getAttribute(LASTNAME);
		if (temp.length() > 10)
			temp = temp.substr(0, 9) + L".";
		std::wcout << L"│" << std::setw(10) << std::right << temp;
		temp = contactBook[i].getAttribute(NICKNAME);
		if (temp.length() > 10)
			temp = temp.substr(0, 9) + L".";
		std::wcout << L"│" << std::setw(10) << std::right << temp << L"│" << std::endl;
		if (i != 7)
			std::wcout << MID_LIST;
		i++;
	}
	std::wcout << MIDDLE;
	std::wcout << L"│ ┌───────────────────────────────────────┐ │\n";
	std::wcout << L"│ │ Please enter the index of the contact │ │\n";
	std::wcout << L"│ │ you would like to display, or 0 to    │ │\n";
	std::wcout << L"│ │ return to the main menu.              │ │\n";
	std::wcout << L"│ └───────────────────────────────────────┘ │\n";
	std::wcout << BOTTOM;
	std::wcout << L"Please enter a command: ";
	if (!getline(std::wcin, command))
		exit(0);
	if (command == L"0")
		return ;
	else if (command == L"1" || command == L"2" || command == L"3" || command == L"4" || command == L"5" || command == L"6" || command == L"7" || command == L"8")
	{
		if (contactBook[command[0] - '0' - 1].getAttribute(FIRSTNAME) != L"")
			displayContact(command[0] - '0' - 1);
		else
			displayEmpty();
	}
	displayList();
}

void	PhoneBook::displayContact(int index)
{
	std::wstring command;

	system("clear");
	std::wcout << TOP << PROMPT_1 << PROMPT_2 << PROMPT_3 << MIDDLE;
	std::wcout << WALL << L"│ First Name: ";
	printFullArgument(contactBook[index].getAttribute(FIRSTNAME), 29);
	std::wcout << WALL << L"│ Last Name: ";
	printFullArgument(contactBook[index].getAttribute(LASTNAME), 30);
	std::wcout << WALL << L"│ Nickname: ";
	printFullArgument(contactBook[index].getAttribute(NICKNAME), 31);
	std::wcout << WALL << L"│ Phone Number: ";
	printFullArgument(contactBook[index].getAttribute(PHONENUMBER), 27);
	std::wcout << WALL << L"│ Darkest Secret: ";
	printFullArgument(contactBook[index].getAttribute(DARKESTSECRET), 25);
	std::wcout << WALL << WALL << WALL;
	std::wcout << MIDDLE;
	std::wcout << L"│ ┌───────────────────────────────────────┐ │\n";
	std::wcout << L"│ │    Enter 0 to return to the list.     │ │\n";
	std::wcout << L"│ └───────────────────────────────────────┘ │\n";
	std::wcout << BOTTOM;
	std::wcout << L"Please enter a command: ";
	if (!getline(std::wcin, command))
		exit(0);
	if (command == L"0")
		return ;
	else
		displayContact(index);
}

void	PhoneBook::addContact(void)
{
	std::wstring	str;

	system("clear");
	std::wcout << TOP << PROMPT_1 << PROMPT_2 << PROMPT_3 << MIDDLE;
	std::wcout << L"│  Please enter the following information:  │\n";
	std::wcout << BOTTOM;
	std::wcout << L"First Name: ";
	if (!getline(std::wcin, str))
		exit(0);
	contactBook[contactIndex].setAttribute(str, FIRSTNAME);
	std::wcout << L"Last Name: ";
	if (!getline(std::wcin, str))
		exit(0);
	contactBook[contactIndex].setAttribute(str, LASTNAME);
	std::wcout << L"Nickname: ";
	if (!getline(std::wcin, str))
		exit(0);
	contactBook[contactIndex].setAttribute(str, NICKNAME);
	std::wcout << L"Phone Number: ";
	if (!getline(std::wcin, str))
		exit(0);
	contactBook[contactIndex].setAttribute(str, PHONENUMBER);
	std::wcout << L"Darkest Secret: ";
	if (!getline(std::wcin, str))
		exit(0);
	contactBook[contactIndex].setAttribute(str, DARKESTSECRET);
	mustFlush();
	if (contactIndex == 8)
		contactIndex = 0;
}

void	PhoneBook::mustFlush(void)
{
	if (contactBook[contactIndex].getAttribute(FIRSTNAME) == L"")
		flushContact(FIRSTNAME);
	else if(contactBook[contactIndex].getAttribute(LASTNAME) == L"")
		flushContact(LASTNAME);
	else if(contactBook[contactIndex].getAttribute(NICKNAME) == L"")
		flushContact(NICKNAME);
	else if(contactBook[contactIndex].getAttribute(PHONENUMBER) == L"")
		flushContact(PHONENUMBER);
	else if(contactBook[contactIndex].getAttribute(DARKESTSECRET) == L"")
		flushContact(DARKESTSECRET);
	else if (wrongNumber())
		flushContact(INVALNUMBER);
	else
		contactIndex++;
}

void	PhoneBook::flushContact(int err)
{
	error = err;
	contactBook[contactIndex].setAttribute(L"", FIRSTNAME);
	contactBook[contactIndex].setAttribute(L"", LASTNAME);
	contactBook[contactIndex].setAttribute(L"", NICKNAME);
	contactBook[contactIndex].setAttribute(L"", PHONENUMBER);
	contactBook[contactIndex].setAttribute(L"", DARKESTSECRET);
}

int	PhoneBook::wrongNumber(void)
{
	int	i;
	std::wstring number;

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
		std::wcout << L"Error: First Name cannot be empty.\n\n";
		break;
	case LASTNAME:
		std::wcout << L"Error: Last Name cannot be empty.\n\n";
		break;
	case NICKNAME:
		std::wcout << L"Error: Nickname cannot be empty.\n\n";
		break;
	case PHONENUMBER:
		std::wcout << L"Error: Phone Number cannot be empty.\n\n";
		break;
	case DARKESTSECRET:
		std::wcout << L"Error: Darkest Secret cannot be empty.\n\n";
		break;
	case INVALNUMBER:
		std::wcout << L"Error: Phone Number must be numeric only.\n\n";
		break;
	case INVALCOMMAND:
		std::wcout << L"Error: Invalid command.\n\n";
		break;
	default:
		break;
	}
	error = 0;
}

void	PhoneBook::displayEmpty(void)
{
	std::wstring	command;
	system("clear");
	std::wcout << TOP << PROMPT_1 << PROMPT_2 << PROMPT_3 << MIDDLE;
	std::wcout << WALL << WALL << L"│  This contact is empty. Please add some   │\n";
	std::wcout << L"│  information to display it.               │\n" << WALL;
	std::wcout << WALL << WALL << L"│ TIP: Use the ADD command to add a new     │\n";
	std::wcout << L"│      contact.                             │\n";
	std::wcout << WALL << WALL << L"│ TIP 2: Try to make some friends.          │\n";
	std::wcout << WALL;
	std::wcout << MIDDLE;
	std::wcout << L"│ ┌───────────────────────────────────────┐ │\n";
	std::wcout << L"│ │    Enter 0 to return to the list.     │ │\n";
	std::wcout << L"│ └───────────────────────────────────────┘ │\n";
	std::wcout << BOTTOM;
	std::wcout << L"Please enter a command: ";
	if (!getline(std::wcin, command))
		exit(0);
	if (command == L"0")
		return ;
	else
		displayEmpty();
}

void	PhoneBook::printFullArgument(std::wstring str, long unsigned int size)
{
	std::wstring	temp;
	
	if (str.length() > size)
	{
		temp = str.substr(size, str.length() - size);
		while (str.length() > size)
		{
			std::wcout << str.substr(0, size) << L" │\n";
			std::wcout << L"│" << std::setw(42 - size) << std::left << L" ";
			str = temp;
			if (str.length() > size)
				temp = str.substr(size, str.length() - size - 1);
		}
		std::wcout << std::setw(size) << std::left << str.substr(0, size) << L" │\n";
	}
	else
		std::wcout << std::setw(size) << std::left <<  str << L" │\n";
}
