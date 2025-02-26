/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:28:01 by txisto-d          #+#    #+#             */
/*   Updated: 2025/02/01 23:00:11 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Array.hpp>
#include <cstdlib>

#define MAX_VAL 5000


#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <exception>


#define RED "\033[31m"
#define GREEN "\033[32m"
#define ORANGE "\033[38;5;208m"
#define PURPLE "\e[35m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define RESET "\033[0m"



static void enter_to_continue()
{
	std::cout << "\n\nPress |ENTER| to continue" << std::endl;
	std::cin.get();
	system("clear");
}

static void TestEmptyArray()
{
	Array<int> array;
	
	try
	{
		std::cout << array[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error succesfull!\n" << std::endl;
		std::cout << RED << e.what() << RESET << std::endl;
	}
	enter_to_continue();
}

static void TestDefaultArray()
{
	Array<int> array(5);
	
	for(size_t i = 0; i < array.size(); i++)
		array[i] = rand() % 100;
	
	for(size_t i = 0; i < array.size(); i++)
		std::cout << CYAN << "index[" << i << "]: " << array[i] << std::endl << RESET;
	enter_to_continue();
}

static void TestCopyArray()
{
	Array<int> array(5);
	
	for(size_t i = 0; i < array.size(); i++)
	{
		array[i] = rand() % 100;
		std::cout << CYAN << "Original index[" << i << "]: " << array[i] << std::endl << RESET;
	}
	
	Array<int> copy(array);
	
	for(size_t i = 0; i < copy.size(); i++)
		std::cout << "Copy index[" << i << "]: " << copy[i] << std::endl;
	enter_to_continue();
}

static void TestAssignArray()
{
	Array<int> array(5);
	
	for(size_t i = 0; i < array.size(); i++)
	{
		array[i] = rand() % 100;
		std::cout << CYAN << "Original index[" << i << "]: " << array[i] << std::endl << RESET;
	}
	
	Array<int> copy(3);
	
	copy = array;
	
	for(size_t i = 0; i < copy.size(); i++)
		std::cout << "Copy index[" << i << "]: " << copy[i] << std::endl;
	enter_to_continue();
}

static void TestAccessingElements()
{
	Array<int> array(5);
	
	for(size_t i = 0; i < array.size(); i++)
	{
		array[i] = rand() % 100;
		std::cout << CYAN << "index[" << i << "]: " << array[i] << std::endl << RESET;
	}
	try
	{
		std::cout << PURPLE << "Trying to access an element within the array limits" << std::endl;
		std::cout << "Element at index 4: " << RESET << std::endl;
		std::cout << array[4] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << PURPLE <<"Trying to access an element out of the array limits" << std::endl;
		std::cout << "Element at index 5: " << RESET << std::endl;
		std::cout << array[5] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	enter_to_continue();
}

static void TestMemberFunction()
{
	Array<int> array(5);

	std::cout << ORANGE << "Array size: " << array.size() << std::endl << RESET;
	enter_to_continue();
}

static void TestChangingElementsAfterCopy()
{
	Array<int> array(5);
	
	for(size_t i = 0; i < array.size(); i++)
	{
		array[i] = rand() % 100;
		std::cout << CYAN << "Before changing copy index[" << i << "]: " << array[i] << std::endl << RESET;
	}
	
	Array<int> copy(array);
	
	for(size_t i = 0; i < copy.size(); i++)
	{
		copy[i] = rand() % 100;
		std::cout << CYAN << "Changed Copy index[" << i << "]: " << copy[i] << std::endl << RESET;
		std::cout << RESET << "After Change index[" << i << "]: " << array[i] << std::endl << RESET;
	}
	enter_to_continue();
}

static void TestChangingElementsAfterAssignment()
{
	Array<int> array(5);
	
	for(size_t i = 0; i < array.size(); i++)
	{
		array[i] = rand() % 100;
		std::cout << CYAN << "Before changing copy index[" << i << "]: " << array[i] << std::endl << RESET;
	}
	
	Array<int> copy(3);
	copy = array;
	
	for(size_t i = 0; i < copy.size(); i++)
	{
		copy[i] = rand() % 100;
		std::cout << CYAN << "Changed Copy index[" << i << "]: " << copy[i] << std::endl << RESET;
		std::cout << RESET << "After Change index[" << i << "]: " << array[i] << std::endl << RESET;
	}
	enter_to_continue();
}












int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (size_t i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (size_t i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (size_t i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;

	std::cout << YELLOW << "--- Test Empty Array ---" << RESET << std::endl;
	TestEmptyArray();
	std::cout << YELLOW << "--- Test Default Array ---" << RESET << std::endl;
	TestDefaultArray();
	std::cout << YELLOW << "--- Test Copy Array ---" << RESET << std::endl;
	TestCopyArray();
	std::cout << YELLOW << "--- Test Assign Array ---" << RESET << std::endl;
	TestAssignArray();
	std::cout << YELLOW << "--- Test Accessing Elements ---" << RESET << std::endl;
	TestAccessingElements();
	std::cout << YELLOW << "--- Test Member Function ---" << RESET << std::endl;
	TestMemberFunction();
	std::cout << YELLOW << "--- Test Changing Copy Function ---" << RESET << std::endl;
	TestChangingElementsAfterCopy();
	std::cout << YELLOW << "--- Test Changing Assignment Function ---" << RESET << std::endl;
	TestChangingElementsAfterAssignment();
	return (0);
}