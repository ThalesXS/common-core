/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:49:49 by txisto-d          #+#    #+#             */
/*   Updated: 2025/01/26 17:23:56 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cmath>
#include <ctime>
#include <iostream>

Base* generate(void)
{
	int n;
	Base* obj;
	
	srand(time(0));
	n = rand() % 3;	
	switch (n)
	{
	case 0:
		obj = new A();
		break;
	case 1:
		obj = new B();
		break;
	case 2:
		obj = new C();
		break;
	}
	return (obj);
}

void	identify(Base* p)
{
	if(dynamic_cast<A*>(p))
	{
		std::cout << "Object is of Type A." << std::endl;
	}
	else if(dynamic_cast<B*>(p))
	{
		std::cout << "Object is of Type B." << std::endl;
	}
	else if(dynamic_cast<C*>(p))
	{
		std::cout << "Object is of Type C." << std::endl;
	}
	else
	{
		std::cout << "No object included." << std::endl;
	}
}

void	identify(Base& p)
{
	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << "Object is of Type A." << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{}
	try
	{
		(void) dynamic_cast<B&>(p);
		std::cout << "Object is of Type B." << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{}
	try
	{
		(void) dynamic_cast<C&>(p);
		std::cout << "Object is of Type C." << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		std::cout << "No object included." << std::endl;
	}
}

int	main(void)
{
	Base* obj;
	Base* emptyptr = 0;

	obj = generate();
	identify(obj);
	identify(*obj);
	identify(NULL);
	identify(emptyptr);
	identify(*emptyptr);
	delete (obj);
	return (0);
}