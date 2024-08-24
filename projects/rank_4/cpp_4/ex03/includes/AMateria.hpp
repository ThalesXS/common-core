/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:57:01 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/23 15:16:53 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		AMateria();
		std::string type;

	public:
		AMateria(std::string const &type);
		virtual ~AMateria();
		AMateria(AMateria& obj);
		AMateria& operator=(const AMateria& obj);

		std::string const &getType() const; // Returns the materia type

		virtual AMateria* clone()const = 0;
		virtual void use(ICharacter &target);
};

typedef AMateria* mat_ptr;

#endif