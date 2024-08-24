/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:10:59 by txisto-d          #+#    #+#             */
/*   Updated: 2024/06/05 18:41:05 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		Cat(Cat& obj);
		Cat&		operator=(const Cat& obj);
		void		makeSound() const;
		void		setIdeaInBrain(std::string idea = "?", unsigned int num = 0);
		std::string	getIdeaFromBrain(unsigned int num) const;
	private:
		Brain*	brain;
};

#endif
