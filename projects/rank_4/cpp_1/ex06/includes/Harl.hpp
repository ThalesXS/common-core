/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:30:22 by txisto-d          #+#    #+#             */
/*   Updated: 2024/05/02 11:27:43 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{
	public:
		void	complain(std::string level);

	private:
		enum	commands
		{
			DEBUG,
			INFO,
			WARNING,
			ERROR
		};
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

typedef void (Harl::*getComplain)(void);

#endif