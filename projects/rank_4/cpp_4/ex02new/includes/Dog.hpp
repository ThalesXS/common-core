/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:10:28 by txisto-d          #+#    #+#             */
/*   Updated: 2024/06/05 18:41:41 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain*	brain;
		
	public:
		Dog(void);
		~Dog(void);
		Dog(Dog& obj);
		Dog& operator=(const Dog& obj);
		void	makeSound() const;
		void		setIdeaInBrain(std::string idea = "", unsigned int num = 0);
		std::string	getIdeaFromBrain(unsigned int num) const;
};

#endif
