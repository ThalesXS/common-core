/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:12:28 by txisto-d          #+#    #+#             */
/*   Updated: 2024/04/27 10:59:04 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define PROMPT_0 "╔──────────────────────────────╗\n"
# define PROMPT_1 "│ ╔═╗┬ ┬┌─┐┌┐┌┌─┐╔╗ ┌─┐┌─┐┬┌─  │\n"
# define PROMPT_2 "│ ╠═╝├─┤│ ││││├┤ ╠╩╗│ ││ │├┴┐  │\n"
# define PROMPT_3 "│ ╩  ┴ ┴└─┘┘└┘└─┘╚═╝└─┘└─┘┴ ┴  │\n"
# define PROMPT_4 "╠───┬────────────┬─────────────╣\n"
# define END_PROM "├───┼────────────┼─────────────┤\n"
# define END_CONT "├───┴─────┬──────┴───┬─────────┤\n"
# define COMMANDS "│   ADD   │  SEARCH  │  EXIT   │\n"
# define END_COMA "╚─────────┴──────────┴─────────╝\n"

class PhoneBook
{
	public:
		PhoneBook(void);
	private:
		int		contactIndex;
		//Contact contactBook[8];
		void	displayBook(void);
};

#endif