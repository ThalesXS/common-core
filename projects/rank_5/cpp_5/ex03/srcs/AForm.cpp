/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:46:58 by txisto-d          #+#    #+#             */
/*   Updated: 2024/12/28 21:51:18 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/*
         ██████   ██████ ███████ 
        ██    ██ ██      ██      
        ██    ██ ██      █████   
        ██    ██ ██      ██      
         ██████   ██████ ██    
*/

AForm::AForm(std::string name, int grade_sign, int grade_exec) : name(name), sign(false), grade_sign(grade_sign), grade_exec(grade_exec)
{
  if(grade_sign < 1)
    throw GradeTooHighException();
  else if (grade_sign > 150)
    throw GradeTooLowException();
  else if(grade_exec < 1)
    throw GradeTooHighException();
  else if (grade_exec > 150)
    throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm& obj) : name(obj.getName()), sign(obj.getSign()), grade_sign(obj.getGradeSign()), grade_exec(obj.getGradeExec()) {}

AForm& AForm::operator=(const AForm& obj)
{
  this->sign = obj.getSign();
  return (*this);
}

/*
         ██████  ███████ ████████     ██ ███████ ███████ ████████ 
        ██       ██         ██       ██  ██      ██         ██    
        ██   ███ █████      ██      ██   ███████ █████      ██    
        ██    ██ ██         ██     ██         ██ ██         ██    
         ██████  ███████    ██    ██     ███████ ███████    ██  
*/

std::string AForm::getName() const
{
  return (this->name);
}

bool AForm::getSign() const
{
  return (this->sign);
}

int AForm::getGradeSign() const
{
  return (this->grade_sign); 
}

int AForm::getGradeExec() const
{
  return (this->grade_exec);
}

void AForm::setSign(const bool sign)
{
  this->sign = sign;
}

/*
        ███    ███ ███████ ████████ ██   ██  ██████  ██████  ███████ 
        ████  ████ ██         ██    ██   ██ ██    ██ ██   ██ ██      
        ██ ████ ██ █████      ██    ███████ ██    ██ ██   ██ ███████ 
        ██  ██  ██ ██         ██    ██   ██ ██    ██ ██   ██      ██ 
        ██      ██ ███████    ██    ██   ██  ██████  ██████  ███████
*/

void AForm::beSigned(const Bureaucrat& bure)
{
  if (this->getSign())
    throw AlreadySignedException();
  else if (bure.getGrade() <= this->getGradeSign())
    this->sign = true;
  else
    throw GradeTooLowException();
}

void AForm::verifyRequirements(const Bureaucrat& executor) const
{
  if (!this->getSign())
    throw NotSignedException();
  else if (executor.getGrade() > this->getGradeExec())
    throw GradeTooLowException();
  else
    this->execute(executor);
}

/*
        ███████ ██   ██  ██████ ███████ ██████  ████████ ██  ██████  ███    ██ ███████ 
        ██       ██ ██  ██      ██      ██   ██    ██    ██ ██    ██ ████   ██ ██      
        █████     ███   ██      █████   ██████     ██    ██ ██    ██ ██ ██  ██ ███████ 
        ██       ██ ██  ██      ██      ██         ██    ██ ██    ██ ██  ██ ██      ██ 
        ███████ ██   ██  ██████ ███████ ██         ██    ██  ██████  ██   ████ ███████
*/

const char* AForm::GradeTooHighException::what() const throw()
{
  return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
  return ("Grade is too low");
}

const char* AForm::AlreadySignedException::what() const throw()
{
  return ("This form is already signed");
}

const char* AForm::NotSignedException::what() const throw()
{
  return ("This form is not signed");
}

/*
          ██   ██      ██████  ██    ██ ███████ ██████  ██       ██████   █████  ██████  
         ██   ██      ██    ██ ██    ██ ██      ██   ██ ██      ██    ██ ██   ██ ██   ██ 
        ██   ██       ██    ██ ██    ██ █████   ██████  ██      ██    ██ ███████ ██   ██ 
         ██   ██      ██    ██  ██  ██  ██      ██   ██ ██      ██    ██ ██   ██ ██   ██ 
          ██   ██      ██████    ████   ███████ ██   ██ ███████  ██████  ██   ██ ██████  
*/

std::ostream& operator<<(std::ostream& out, AForm& in)
{
  out << "Form: " << in.getName() << std::endl;
  out << "Grade to sign: " << in.getGradeSign() << std::endl;
  out << "Grade to execute: " << in.getGradeExec() << std::endl;
  out << "Signed: " << std::boolalpha << in.getSign() << std::noboolalpha << std::endl;
  return (out);
}