/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:44:47 by fde-carv          #+#    #+#             */
/*   Updated: 2024/02/02 09:45:16 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip> // --> setw()
# include <cstdlib> // --> atoi()

# define CLEAR "\033c"

class Contact
{
	private:
		std::string	_FirstName;
		std::string	_LastName;
		std::string	_NickName;
		std::string	_PhoneNumber;
		std::string	_DarkSecret;

	public:
    	Contact();
		~Contact();
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickName();
		std::string	getPhoneNumber();
		std::string	getDarksecret();
		void		getInfo();
		void		setInfo();
};

    std::string	readInput(std::string str);
    std::string	formatString(std::string str);
    bool		is_number(std::string str);

#endif