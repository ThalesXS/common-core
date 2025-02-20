/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:06:39 by txisto-d          #+#    #+#             */
/*   Updated: 2024/06/05 17:55:00 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string type;
	
	public:
		Animal(std::string animal = "Animal");
		virtual ~Animal();
		Animal(Animal& obj);
		Animal& operator=(const Animal& obj);
		virtual void	makeSound() const;
		std::string	getType(void) const;
};

#endif
