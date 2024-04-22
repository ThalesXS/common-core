/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:44:31 by fde-carv          #+#    #+#             */
/*   Updated: 2024/02/03 13:39:11 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

std::string	Contact::getFirstName()
{
	return (_FirstName);
}

std::string	Contact::getLastName()
{
	return (_LastName);
}

std::string	Contact::getNickName()
{
	return (_NickName);
}

std::string	Contact::getPhoneNumber()
{
	return (_PhoneNumber);
}

std::string	Contact::getDarksecret()
{
	return (_DarkSecret);
}

/*
--> Prints out the information of a contact in a formatted manner.
  The `std::setw(16)` manipulator is used to set the field width for the next insertion operation. 
*/
void	Contact::getInfo()
{
    std::cout << CLEAR;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "|                   CONTACT VIEWER                  |" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl << std::endl;
	std::cout << std::setw(16) << "First Name: " << getFirstName() << "\n";
	std::cout << std::setw(16) << "Last Name: " << getLastName() << "\n";
	std::cout << std::setw(16) << "Nick Name: " << getNickName() << "\n";
	std::cout << std::setw(16) << "Phone Number: " << getPhoneNumber() << "\n";
	std::cout << std::setw(16) << "Darkest Secret: " << getDarksecret() << "\n";
    std::cout << "\nPress ENTER to continue." << std::endl;
	std::cin.ignore();
}
/*
--> Sets the information of a new contact.
*/
void	Contact::setInfo()
{
    std::cout << CLEAR;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "|                  ADD NEW CONTACT                  |" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl << std::endl;
	_FirstName = readInput("First Name: ");
	_LastName = readInput("Last Name: ");
	_NickName = readInput("Nick Name: ");
    while(1)
    {
        std::string phoneNumberInput = readInput("Phone Number: ");
        if ((phoneNumberInput[0] == '+' && phoneNumberInput.size() > 1 && is_number(phoneNumberInput.substr(1)))
            || (phoneNumberInput[0] != '+' && is_number(phoneNumberInput)))
        {
            _PhoneNumber = phoneNumberInput;
            break ;   
        }
        else    
            std::cout << "The first char must be [+] or a [number].\nFrom second char onward, only number(s) are allowed." << "\n"; 
    }
	_DarkSecret = readInput("Darkest Secret: ");
}

/*
--> Checks errors in reading the getline function.
  While the input is empty, it checks if the getline function failed.
  If so it exits the program with code error (1). If not, it gets the input.
*/
std::string	readInput(std::string str)
{
	std::string	input;

    while (input.empty())
    {
        std::cout << str;
        if (!std::getline(std::cin, input))
        {
            std::cout << "\n\nError: reading getline\n";
            exit(1);
        }
    }
    return (input);
}

/*
--> Formating the string to fit the table (with 9 caracters).
  If the size of the string is greater than 9, the function creates a new string
  that consists of the first 9 characters of the input string. This is done using
  the `substr()` method, which returns a new string that is a substring of the
  original string. The `substr(0, 9)` call starts at position 0 (the beginning
  of the string) and takes 9 characters.
  After obtaining the substring, the function appends a period (".") to the end
  of it using the `append()` method. The `append()` method modifies the string by
  adding the specified characters to the end of it.
*/
std::string	formatString(std::string str)
{
	if (str.size() <= 9)
		return (str);
	else
	{
		std::string format = str.substr(0, 9).append(".");
		return (format);
	}
}

/*
--> Checks if the string is a number.
  Uses size_t because .size is an long unsigned int
*/
bool	is_number(std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
		if (!std::isdigit(str[i]))
			return (false);
	return (true);
}
