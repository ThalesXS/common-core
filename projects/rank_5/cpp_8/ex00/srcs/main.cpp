/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:30:42 by txisto-d          #+#    #+#             */
/*   Updated: 2025/02/09 03:31:54 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>

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

static void TestWithVector()
{
	std::vector<int> vec;

	for (int i = 0; i < 10; i++)
		vec.push_back(i);

	std::cout << YELLOW << "Testing with a vector of integers" << RESET << std::endl;
	std::cout << "Vector: ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	try
	{
		std::cout << "Searching for 5: ";
		std::cout << GREEN << easyfind(vec, 5) << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED << "Element not found" << RESET << std::endl;
	}

	try
	{
		std::cout << "Searching for 10: ";
		std::cout << GREEN << easyfind(vec, 10) << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	enter_to_continue();
}

static void TestWithDeque()
{
    std::deque<int> deq;

    for (int i = 0; i < 10; i++)
        deq.push_back(i);

    std::cout << YELLOW << "Testing with a deque of integers" << RESET << std::endl;
    std::cout << "Deque: ";
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    try
    {
        std::cout << "Searching for 5: ";
        std::cout << GREEN << easyfind(deq, 5) << RESET << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << RED << "Element not found" << RESET << std::endl;
    }

    try
    {
        std::cout << "Searching for 10: ";
        std::cout << GREEN << easyfind(deq, 10) << RESET << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    enter_to_continue();
}

int main()
{
	TestWithVector();
	TestWithDeque();
	return (0);
}