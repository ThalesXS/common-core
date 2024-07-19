/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:18:53 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/19 16:34:23 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
				Ice();
				~Ice();
				Ice(Ice& obj);
		Ice&	operator=(const Ice& obj);
		Ice*	clone() const;
		void	use(ICharacter &target);
};

#endif