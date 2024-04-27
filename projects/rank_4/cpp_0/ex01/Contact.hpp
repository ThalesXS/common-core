/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:15:25 by txisto-d          #+#    #+#             */
/*   Updated: 2024/04/27 10:59:11 by txisto-d         ###   ########.fr       */
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
	FIRSTNAME,
	LASTNAME,
	PHONENUMBER,
	DARKESTSECRET
}	attributeType;

//	====================			CLASSES					====================

class Contact
{
	private:
		string	firstName;
		string	lastName;
		string	phoneNumber;
		string	darkestSecret;
		enum	attributeType
		{
			FIRSTNAME,
			LASTNAME,
			PHONENUMBER,
			DARKESTSECRET
		};

	public:
		Contact(void);
		void	setAttribute(string str, attributeType attr);
		string	getAttribute(attributeType attr);
		/* void	setFirstName(string name);
		string	getFirstName(void);
		void	setLastName(string name);
		string	getLastName(void);
		void	setPhoneNumber(string number);
		string	getPhoneNumber(void);
		void	setDarkestSecret(string secret);
		string	getDarkestSecret(void); */
};

#endif