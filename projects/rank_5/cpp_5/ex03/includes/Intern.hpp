/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:59:29 by txisto-d          #+#    #+#             */
/*   Updated: 2024/12/28 22:18:36 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShruberryCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <iostream>

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(Intern& obj);
		Intern& operator=(Intern& obj);

		AForm* makeForm(std::string name, std::string target);
	private:
		AForm* (Intern::*makeArray[3])(std::string target);
		std::string formNames[3];
		AForm* makeShruberry(std::string target);
		AForm* makeRobotomy(std::string target);
		AForm* makePresidential(std::string target);

	class FormNotFoundException : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

# endif