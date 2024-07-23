/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:21:35 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/23 15:53:34 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_HPP
# define FLOOR_HPP

# include "AMateria.hpp"

class Floor
{
	private:
		AMateria**	droppedItems;
		int			amount;
		
	public:
		Floor();
		~Floor();
		Floor(Floor& obj);
		Floor& operator=(Floor& obj);
		void				setDroppedItems(AMateria** items);
		AMateria**			getDroppedItems();
		int					length();
		void				push(AMateria* materia);
		void				erase();
};

#endif