/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:14:37 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/19 16:34:03 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
				Cure();
				~Cure();
				Cure(Cure& obj);
		Cure&	operator=(const Cure& obj);
		Cure*	clone() const;
		void	use(ICharacter &target);
};

#endif