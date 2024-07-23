/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:00:53 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/20 17:49:47 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*	pages[4];
		int			materias;
		
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(MateriaSource& obj);
		MateriaSource& operator=(MateriaSource& obj);

		void		learnMateria(AMateria* materia);
		AMateria*	createMateria(std::string const & type);

		int			getMaterias();
		AMateria*	getPages(int index);
};

#endif

/*
• LearnMateria(AMateria*)

	Copies the Materia passed as a parameter and store it in memory so it can be cloned
	later. Like the Character, the MateriaSource can know at most 4 Materias. They
	are not necessarily unique.


• createMateria(std::string const &)

	Returns a new Materia. The latter is a copy of the Materia previously learned by
	the MateriaSource whose type equals the one passed as parameter. Returns 0 if
	the type is unknown. */