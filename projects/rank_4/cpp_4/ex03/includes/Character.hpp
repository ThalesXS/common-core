/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:42:40 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/23 15:52:56 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		AMateria*		inventory[4];
		std::string		name;
		int				items;
		AMateria*		floor[50];
		int				trashAmount;
		
	public:
		Character(std::string name="random");
		~Character();
		Character(Character& obj);
		Character& operator=(Character& obj);
		
		std::string const &	getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
		int					getItems() const;
		AMateria*			getInventory(int index) const;
		AMateria**			getFloor();
		void				addToFloor(AMateria* materia);
};

#endif
