/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:28:27 by txisto-d          #+#    #+#             */
/*   Updated: 2024/06/05 18:26:22 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	private:
		std::string	ideas[100];
	
	public:
		Brain(void);
		~Brain(void);
		Brain(Brain& obj);
		Brain& operator=(Brain& obj);
		void		setIdea(std::string idea = "", unsigned int num = 0);
		std::string	getIdea(unsigned int num);
};

#endif