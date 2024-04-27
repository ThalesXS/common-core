/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:15:20 by txisto-d          #+#    #+#             */
/*   Updated: 2024/04/27 21:20:28 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

string	Contact::strTrim(string str)
{
	if (str.empty())
		return ("");
	return (str.substr(str.find_first_not_of(" \t\n"),
			str.find_last_not_of(" \t\n") \
			+ 1 - str.find_first_not_of(" \t\n")));
}

void	Contact::setAttribute(string str, attributeType attr)
{
	str = strTrim(str);
	switch(attr)
	{
		case (FIRSTNAME):
			firstName = str;
			break ;
		case (LASTNAME):
			lastName = str;
			break ;
		case (NICKNAME):
			nickname = str;
			break ;
		case (PHONENUMBER):
			phoneNumber = str;
			break ;
		case (DARKESTSECRET):
			darkestSecret = str;
			break ;
		default:
			;
	}
}

string	Contact::getAttribute(attributeType attr)
{
	switch(attr)
	{
		case (FIRSTNAME):
			return (firstName);
			break ;
		case (LASTNAME):
			return (lastName);
			break ;
		case (NICKNAME):
			return (nickname);
			break ;
		case (PHONENUMBER):
			return (phoneNumber);
			break ;
		case (DARKESTSECRET):
			return (darkestSecret);
			break ;
		default:
			return ("");
	}
}