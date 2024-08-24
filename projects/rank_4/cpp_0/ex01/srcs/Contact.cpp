/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:15:20 by txisto-d          #+#    #+#             */
/*   Updated: 2024/08/24 02:01:08 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::wstring	Contact::strTrim(std::wstring str)
{
	if (str.empty())
		return (L"");
	return (str.substr(str.find_first_not_of(L" \t\n"),
			str.find_last_not_of(L" \t\n") \
			+ 1 - str.find_first_not_of(L" \t\n")));
}

void	Contact::setAttribute(std::wstring str, attributeType attr)
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

std::wstring	Contact::getAttribute(attributeType attr)
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
			return (L"");
	}
}