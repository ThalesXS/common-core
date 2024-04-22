/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:52:38 by fde-carv          #+#    #+#             */
/*   Updated: 2024/02/02 17:58:00 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

class PhoneBook
{
	private:
		Contact	_contacts[8];
		int		_size;
		int		_index;
		int		_spaces;

	public:
		PhoneBook();
		~PhoneBook();
		void	addContact();
		void	searchContact();
		void	displaySearch(int spacing);
        void    initPhone();
		Contact	getContact(int index);
		
};

#endif