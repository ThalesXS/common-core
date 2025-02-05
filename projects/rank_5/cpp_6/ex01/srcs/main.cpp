/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:15:04 by txisto-d          #+#    #+#             */
/*   Updated: 2025/01/26 16:38:53 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.hpp"
#include "utils.hpp"
#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data person;
	Data* pointer = &person;
	Data* newPointer;
	uintptr_t address;

	person.name = "Thales";
	person.age = 26;
	std::cout << "person address = [" << pointer << "]\n";
	std::cout << "person name = [" << pointer->name << "]\n";
	std::cout << "person age = [" << pointer->age << "]\n";
	address = Serializer::serialize(pointer);
	std::cout << "Serialized address = [" << address << "]\n";
	newPointer = Serializer::deserialize(address);
	std::cout << "person address = [" << newPointer << "]\n";
	std::cout << "person name = [" << newPointer->name << "]\n";
	std::cout << "person age = [" << newPointer->age << "]\n";
	return (0);
}