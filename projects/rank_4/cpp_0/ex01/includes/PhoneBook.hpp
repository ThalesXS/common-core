/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:12:28 by txisto-d          #+#    #+#             */
/*   Updated: 2024/04/27 23:48:21 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define TOP		"╔───────────────────────────────────────────╗\n"
# define PROMPT_1	"│        ╔═╗┬ ┬┌─┐┌┐┌┌─┐╔╗ ┌─┐┌─┐┬┌─        │\n"
# define PROMPT_2	"│        ╠═╝├─┤│ ││││├┤ ╠╩╗│ ││ │├┴┐        │\n"
# define PROMPT_3	"│        ╩  ┴ ┴└─┘┘└┘└─┘╚═╝└─┘└─┘┴ ┴        │\n"
# define START_LIST	"╠──────────┬──────────┬──────────┬──────────╣\n"
# define MID_LIST	"├──────────┼──────────┼──────────┼──────────┤\n"
# define END_LIST	"╚──────────┴──────────┴──────────┴──────────╝\n"
# define MIDDLE		"╠───────────────────────────────────────────╣\n"
# define MIDDLE_2	"├───────────────────────────────────────────┤\n"
# define WALL		"│                                           │\n"
# define BOTTOM		"╚───────────────────────────────────────────╝\n"

class PhoneBook
{
	public:
		PhoneBook(void);
	private:
	enum	commandType
	{
		ADD,
		SEARCH,
		EXIT
	};
		int		contactIndex;
		Contact contactBook[8];
		void	displayIntro(void);
		void	displayList(void);
		void	displayContact(int index);
		void	addContact(void);
		void 	mustFlush(void);
		void	flushContact(int err);
		int		wrongNumber(void);
		void	printError(void);
		void	displayEmpty(void);
		void	printFullArgument(string str, long unsigned int size);
		int		error;
};

#endif