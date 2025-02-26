/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:33:52 by txisto-d          #+#    #+#             */
/*   Updated: 2025/02/11 19:12:27 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>

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

static void subjectTest()
{
	try
	{
		Span sp(5);

		std::cout << ORANGE << "Adding numbers to the deque..." << std::endl << RESET;
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << std::endl;
		sp.printSortedUnique();
		std::cout << std::endl;
		std::cout << CYAN <<"Shortest Span: "  << RESET << sp.shortestSpan() << std::endl;
		std::cout << CYAN << "Longest Span: " << RESET << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	enter_to_continue();
}

static void spanUsingIterators()
{

	try
	{
		std::deque<int> v;
		std::deque<int>::iterator begin;
		std::deque<int>::iterator end;

		std::cout << ORANGE << "Adding numbers to deque..." << std::endl << RESET;
		for(unsigned int i = 0; i < 10; i++)
		{
			v.push_back(rand() % 100);
			std::cout << PURPLE << "Deque Value: " << RESET << v[i] << std::endl;
		}

		Span span(10);

		begin = v.begin();
		end = v.end();

		std::cout << std::endl;
		std::cout << ORANGE << "Adding numbers to data deque using range of iterators..." << std::endl << RESET;
		span.addRange(begin, end);
		std::cout << std::endl;
		span.printSortedUnique();
		std::cout << std::endl;
		std::cout << CYAN << "Shortest Span: "  << RESET << span.shortestSpan() << std::endl;
		std::cout << CYAN << "Longest Span: " << RESET << span.longestSpan() << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	enter_to_continue();
}


static void testExceptions()
{
	try
	{
		Span sp(5);

		std::cout << ORANGE << "Add Numbers Exception" << std::endl << RESET;
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(11);
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	try
	{
		Span sp(1);

		std::cout << std::endl;
		std::cout << ORANGE << "Shortest/Longest Span Exception" << std::endl << RESET;
		sp.addNumber(5);

		std::cout << std::endl;
		std::cout << CYAN << "Shortest Span: "  << RESET << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	enter_to_continue();
}

static void testThousands()
{

	try
	{
		std::deque<int> v;
		std::deque<int>::iterator begin;
		std::deque<int>::iterator end;

		std::cout << ORANGE << "Adding numbers to deque..." << std::endl << RESET;
		for(unsigned int i = 0; i < 10000; i++)
		{
			v.push_back(rand() % 100);
			std::cout << PURPLE << "Deque Value: " << RESET << v[i] << std::endl;
		}

		Span span(100000);

		begin = v.begin();
		end = v.end();

		std::cout << std::endl;
		std::cout << ORANGE << "Adding numbers to data deque using range of iterators..." << std::endl << RESET;
		span.addRange(begin, end);
		std::cout << std::endl;
		span.printSortedUnique();
		std::cout << std::endl;
		clock_t start = clock();
		std::cout << CYAN <<"Shortest Span: "  << RESET << span.shortestSpan() << std::endl;
		std::cout << "Time taken: " << (float)(clock() - start)/CLOCKS_PER_SEC << " seconds" << std::endl;
		start = clock();
		std::cout << CYAN << "Longest Span: " << RESET << span.longestSpan() << std::endl;
		std::cout << "Time taken: " << (float)(clock() - start)/CLOCKS_PER_SEC << " seconds" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	enter_to_continue();
}

int main()
{
	srand(time(NULL));
	subjectTest();
	spanUsingIterators();
	testExceptions();
	testThousands();
	return (0);
}