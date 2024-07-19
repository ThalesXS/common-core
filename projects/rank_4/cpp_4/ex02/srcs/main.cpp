/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:06:49 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/19 15:59:20 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	//const Animal* m = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal* k = new Animal();
	delete j;//should not create a leak
	delete i;
	return 0;
}