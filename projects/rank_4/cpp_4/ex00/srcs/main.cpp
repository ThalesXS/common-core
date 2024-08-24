/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:06:49 by txisto-d          #+#    #+#             */
/*   Updated: 2024/08/24 10:53:15 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " ---" << std::endl;
	std::cout << i->getType() << " ---" << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	const WrongAnimal* beta = new WrongAnimal();
	const WrongAnimal* m = new WrongCat();
	const WrongCat* n = new WrongCat();
	std::cout << m->getType() << " ---" << std::endl;
	m->makeSound();
	beta->makeSound();
	n->makeSound();
	delete meta;
	delete j;
	delete i;
	delete beta;
	delete m;
	delete n;
	return 0;
}