/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:15:25 by txisto-d          #+#    #+#             */
/*   Updated: 2024/04/27 21:18:05 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <cstdlib>
# include <iomanip>
# include <iostream>

# ifndef USING_STRING
# define USING_STRING
	using std::string;
# endif

//	====================			ENUMS					====================

typedef enum	e_attributeType
{
	FIRSTNAME = 1,
	LASTNAME,
	NICKNAME,
	PHONENUMBER,
	DARKESTSECRET,
	INVALNUMBER,
	INVALCOMMAND
}	attributeType;

//	====================			CLASSES					====================

class Contact
{
	private:
		string	firstName;
		string	lastName;
		string	nickname;
		string	phoneNumber;
		string	darkestSecret;

	public:
		void	setAttribute(string str, attributeType attr);
		string	getAttribute(attributeType attr);
		string	strTrim(string str);
};

#endif