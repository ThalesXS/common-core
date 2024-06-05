/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:10:28 by txisto-d          #+#    #+#             */
/*   Updated: 2024/06/01 14:16:25 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	protected:
		std::string type;
	
	public:
		Dog();
		~Dog();
		Dog(Dog& obj);
		Dog& operator=(const Dog& obj);
		void	makeSound();
};

#endif
