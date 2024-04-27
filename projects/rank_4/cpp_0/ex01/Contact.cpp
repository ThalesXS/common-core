/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:15:20 by txisto-d          #+#    #+#             */
/*   Updated: 2024/04/27 00:19:53 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
 
}

void	Contact::setAttribute(string str, attributeType attr)
{
	switch(attr)
	{
		case (FIRSTNAME):
			firstName = str;
			break ;
		case (LASTNAME):
			lastName = str;
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