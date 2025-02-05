/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:45:50 by txisto-d          #+#    #+#             */
/*   Updated: 2024/12/28 21:53:24 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void step(std::string msg = "")
{
	std::cout << "\n\nPress [Enter] to continue\n";
	std::cin.get();
	system("clear");
	if (msg != "")
		std::cout << ">>>>> " << msg << " <<<<<" << std::endl << std::endl;
}

static void goodForms()
{
	try
	{
		Bureaucrat b1("Bureaucrat1", 1);
		ShruberryCreationForm form("file");
		b1.signForm(form);
		std::cout << std::endl << form << std::endl;
		b1.executeForm(form);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	step("Good ROBOTOMY");
	try
	{
		Bureaucrat b1("Bureaucrat1", 1);
		RobotomyRequestForm form("Joe");
		b1.signForm(form);
		std::cout << std::endl << form << std::endl;
		b1.executeForm(form);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	step("Good PRESIDENTIAL");
	try
	{
		Bureaucrat b1("Bureaucrat1", 1);
		PresidentialPardonForm form("Jack");
		b1.signForm(form);
		std::cout << std::endl << form << std::endl;
		b1.executeForm(form);
	}
		catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}


static void badSign()
{
	try
	{
		Bureaucrat b1("Bureaucrat1", 150);
		ShruberryCreationForm form("fail");
		b1.signForm(form);
		std::cout << std::endl << form << std::endl;
		b1.executeForm(form);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	step("Bad Sign ROBOTOMY");
	try
	{
		Bureaucrat b1("Bureaucrat1", 150);
		RobotomyRequestForm form("Thales");
		b1.signForm(form);
		std::cout << std::endl << form << std::endl;
		b1.executeForm(form);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	step("Bad Sign PRESIDENTIAL");
	try
	{
		Bureaucrat b1("Bureaucrat1", 150);
		PresidentialPardonForm form("Jeffrey");
		b1.signForm(form);
		std::cout << std::endl << form << std::endl;
		b1.executeForm(form);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

static void twiceSign()
{
	try
	{
		Bureaucrat b1("Bureaucrat1", 1);
		ShruberryCreationForm form("file");
		b1.signForm(form);
		std::cout << std::endl << form << std::endl;
		b1.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

static void badExecute()
{
	try
	{
		Bureaucrat b1("Bureaucrat1", 145);
		ShruberryCreationForm form("file");
		b1.signForm(form);
		std::cout << std::endl << form << std::endl;
		b1.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	step("Bad Execute ROBOTOMY");
	try
	{
		Bureaucrat b1("Bureaucrat1", 72);
		RobotomyRequestForm form("Joe");
		b1.signForm(form);
		std::cout << std::endl << form << std::endl;
		b1.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	step("Bad Execute PRESIDENTIAL");
	try
	{
		Bureaucrat b1("Bureaucrat1", 25);
		PresidentialPardonForm form("Jack");
		b1.signForm(form);
		std::cout << std::endl << form << std::endl;
		b1.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	copy()
{
	try
	{
		Bureaucrat b1("Bureaucrat1", 1);
		ShruberryCreationForm form("file");
		ShruberryCreationForm form2(form);
		b1.signForm(form);
		std::cout << std::endl << form << std::endl;
		std::cout << std::endl << form2 << std::endl;
		form2 = form;
		std::cout << std::endl << form2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	step("Copy");
	try
	{
		Bureaucrat b1("Bureaucrat1", 1);
		RobotomyRequestForm form("Joe");
		b1.signForm(form);
		RobotomyRequestForm form2(form);
		std::cout << std::endl << form << std::endl;
		std::cout << std::endl << form2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main(void)
{
	step("Good SHRUBERRY");
	goodForms();
	step("Bad Sign SHRUBERRY");
	badSign();
	step("Sign Twice");
	twiceSign();
	step("Bad Execute SHRUBERRY");
	badExecute();
	step("= Operator");
	copy();
	return (0);
}