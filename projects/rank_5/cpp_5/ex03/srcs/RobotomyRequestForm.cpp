/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:17:47 by txisto-d          #+#    #+#             */
/*   Updated: 2024/12/28 21:08:02 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& obj) : AForm(obj), _target(obj.getTarget()) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& obj)
{
	this->setSign(obj.getSign());
	return (*this);
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	(void) executor;
	std::cout << "**rizzz, bzzzzzz**" << std::endl;
	if (rand() % 2)
		std::cout << this->getTarget() << " has been robotomized." << std::endl;
	else
		std::cout << "ROBOTOMY FAILED!!!\n";
}

std::string RobotomyRequestForm::getTarget() const
{
    return (this->_target);
}