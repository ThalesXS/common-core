/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:52:19 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/19 16:05:56 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	
	public:
		WrongAnimal(std::string animal = "Wrong Animal");
		virtual ~WrongAnimal();
		WrongAnimal(WrongAnimal& obj);
		WrongAnimal& operator=(const WrongAnimal& obj);
		virtual void	makeSound() const;
		std::string	getType(void) const;
};

#endif