/* ************************************************************************** */
/*                                                                        */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 22:18:50 by txisto-d          #+#    #+#             */
/*   Updated: 2024/11/23 13:14:42 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShruberryCreationForm.hpp"

ShruberryCreationForm::ShruberryCreationForm(std::string target) : AForm(name, 145, 137), _target(target) {}

ShruberryCreationForm::~ShruberryCreationForm() {}

ShruberryCreationForm::ShruberryCreationForm(ShruberryCreationForm& obj) : AForm(obj), _target(obj.getTarget()) {}

ShruberryCreationForm& ShruberryCreationForm::operator=(ShruberryCreationForm& obj)
{
  this->setSign(obj.getSign());
  return (*this);
}


void ShruberryCreationForm::execute(Bureaucrat const & executor) const
{
  (void) executor;
  std::ofstream file((this->getName() + "_shruberry").c_str(), std::ios::trunc);
  std::string tree = "               ,@@@@@@@,\n"
                     "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
                     "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
                     "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
                     "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
                     "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
                     "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
                     "       |o|        | |         | |\n"
                     "       |.|        | |         | |\n"
                     "    \\\\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";
  file << tree << std::endl;
}

std::string ShruberryCreationForm::getTarget() const
{

}