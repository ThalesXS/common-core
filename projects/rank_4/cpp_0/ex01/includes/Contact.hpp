/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:15:25 by txisto-d          #+#    #+#             */
/*   Updated: 2024/08/24 02:07:55 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <locale>

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
		std::wstring	firstName;
		std::wstring	lastName;
		std::wstring	nickname;
		std::wstring	phoneNumber;
		std::wstring	darkestSecret;

	public:
		void	setAttribute(std::wstring str, attributeType attr);
		std::wstring	getAttribute(attributeType attr);
		std::wstring	strTrim(std::wstring str);
};

#endif