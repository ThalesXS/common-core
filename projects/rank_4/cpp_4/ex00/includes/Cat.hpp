/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:10:59 by txisto-d          #+#    #+#             */
/*   Updated: 2024/06/01 14:21:06 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	protected:
		std::string type;
	
	public:
		Cat();
		~Cat();
		Cat(Cat& obj);
		Cat&	operator=(const Cat& obj);
		void	makeSound();
};

#endif
