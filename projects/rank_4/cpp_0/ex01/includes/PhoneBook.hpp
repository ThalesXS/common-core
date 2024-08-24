/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:12:28 by txisto-d          #+#    #+#             */
/*   Updated: 2024/08/24 02:17:28 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define TOP		L"╔───────────────────────────────────────────╗\n"
# define PROMPT_1	L"│        ╔═╗┬ ┬┌─┐┌┐┌┌─┐╔╗ ┌─┐┌─┐┬┌─        │\n"
# define PROMPT_2	L"│        ╠═╝├─┤│ ││││├┤ ╠╩╗│ ││ │├┴┐        │\n"
# define PROMPT_3	L"│        ╩  ┴ ┴└─┘┘└┘└─┘╚═╝└─┘└─┘┴ ┴        │\n"
# define START_LIST	L"╠──────────┬──────────┬──────────┬──────────╣\n"
# define MID_LIST	L"├──────────┼──────────┼──────────┼──────────┤\n"
# define END_LIST	L"╚──────────┴──────────┴──────────┴──────────╝\n"
# define MIDDLE		L"╠───────────────────────────────────────────╣\n"
# define MIDDLE_2	L"├───────────────────────────────────────────┤\n"
# define WALL		L"│                                           │\n"
# define BOTTOM		L"╚───────────────────────────────────────────╝\n"

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
		void	printFullArgument(std::wstring str, long unsigned int size);
		int		error;
};

#endif