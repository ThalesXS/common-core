/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:02:58 by txisto-d          #+#    #+#             */
/*   Updated: 2024/12/28 22:29:02 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	this->makeArray[0] = &Intern::makeShruberry;
	this->formNames[0] = "shruberry creation";
	this->makeArray[1] = &Intern::makeRobotomy;
	this->formNames[1] = "robotomy request";
	this->makeArray[2] = &Intern::makePresidential;
	this->formNames[2] = "presidential pardon";
}

Intern::~Intern() {}

Intern::Intern(Intern& obj)
{
	*this = obj;
}

Intern& Intern::operator=(Intern& obj)
{
	(void) obj;
	return (*this);
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	for (int i = 0; i < 3; i++)
	{
		if (name == this->formNames[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return (this->*makeArray[i])(target);
		}
	}
	throw FormNotFoundException();
}

AForm* Intern::makeShruberry(std::string target)
{
	return (new ShruberryCreationForm(target));
}

AForm* Intern::makeRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makePresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return ("Form not found");
}