/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:06:49 by txisto-d          #+#    #+#             */
/*   Updated: 2024/08/24 13:09:58 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void	testBrains(Dog *src, Dog *dest);
void	testArray();

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	Dog* m = new Dog();
	Dog* n = new Dog();
	
	
	testBrains(m, n);
	testArray();
	delete j;//should not create a leak
	delete i;
	delete n;
	return 0;
}

void	testBrains(Dog *src, Dog *dest)
{
	unsigned int	i;

	i = 0;
	while (i < 100)
	{
		src->setIdeaInBrain("food!", i);
		i++;
	}
	std::cout << dest->getIdeaFromBrain(0) << std::endl;
	*dest = *src;
	std::cout << src->getIdeaFromBrain(0) << std::endl;
	std::cout << dest->getIdeaFromBrain(0) << std::endl;
	delete src;
	std::cout << dest->getIdeaFromBrain(0) << std::endl;
}

void	testArray()
{
	Animal *animals[4] = 
	{
		new Dog(),
		new Dog(),
		new Cat(),
		new Cat()
	};

	for (int i = 0; i < 4; i++)
		delete animals[i];
}