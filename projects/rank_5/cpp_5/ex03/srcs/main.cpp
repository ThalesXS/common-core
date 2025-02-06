/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:45:50 by txisto-d          #+#    #+#             */
/*   Updated: 2024/12/28 22:37:24 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define ORANGE "\033[38;5;208m"
#define PURPLE "\e[35m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

static void step(std::string msg = "")
{
	std::cout << "\n\nPress [Enter] to continue\n";
	std::cin.get();
	system("clear");
	if (msg != "")
		std::cout << ">>>>> " << msg << " <<<<<" << std::endl << std::endl;
}

static void createForms()
{
	Intern intern;
	try
	{
		Bureaucrat b1("Bureaucrat1", 1);
		AForm* form = intern.makeForm("shruberry creation", "Joe");
		b1.signForm(*form);
		std::cout << std::endl << CYAN << *form << RESET << std::endl;
		b1.executeForm(*form);
		delete form;
	}
	catch(std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	step("Good ROBOTOMY");
	try
	{
		Bureaucrat b1("Bureaucrat1", 1);
		AForm* form = intern.makeForm("robotomy request", "Joe");
		b1.signForm(*form);
		std::cout << std::endl << CYAN << *form << RESET << std::endl;
		b1.executeForm(*form);
		delete form;
	}
	catch(std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	step("Good PRESIDENTIAL");
	try
	{
		Bureaucrat b1("Bureaucrat1", 1);
		AForm* form = intern.makeForm("presidential pardon", "Joe");
		b1.signForm(*form);
		std::cout << std::endl << CYAN << *form << RESET << std::endl;
		b1.executeForm(*form);
		delete form;
	}
		catch(std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	step("Form not Found");
	try
	{
		Bureaucrat b1("Bureaucrat1", 1);
		AForm* form = intern.makeForm("create excalibur", "Joe");
		b1.signForm(*form);
		std::cout << std::endl << CYAN << *form << RESET << std::endl;
		b1.executeForm(*form);
		delete form;
	}
		catch(std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

void	copyCreate()
{
	Intern intern;
	
	try
	{
		Bureaucrat b1("Bureaucrat1", 1);
		AForm* form = intern.makeForm("shruberry creation", "Joe");
		b1.signForm(*form);
		std::cout << std::endl << CYAN << *form << RESET << std::endl;
		AForm* form2 = intern.makeForm("shruberry creation", "Joe");
		*form2 = *form;
		std::cout << std::endl << CYAN << *form2 << RESET << std::endl;
		delete form;
		delete form2;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	
}

int main(void)
{
	step("Create SHRUBERRY");
	createForms();
	step("Create with copy");
	copyCreate();
	return (0);
}