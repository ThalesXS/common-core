/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:46:58 by txisto-d          #+#    #+#             */
/*   Updated: 2024/11/22 22:01:14 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*
         ██████   ██████ ███████ 
        ██    ██ ██      ██      
        ██    ██ ██      █████   
        ██    ██ ██      ██      
         ██████   ██████ ██    
*/

Form::Form(std::string name, int grade_sign, int grade_exec) : name(name), sign(false), grade_sign(grade_sign), grade_exec(grade_exec)
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

Form::~Form()
{
  
}
Form::Form(const Form& obj) : name(obj.getName()), sign(obj.getSign()), grade_sign(obj.getGradeSign()), grade_exec(obj.getGradeExec()) {}

Form& Form::operator=(const Form& obj)
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

std::string Form::getName() const
{
  return (this->name);
}

bool Form::getSign() const
{
  return (this->sign);
}

int Form::getGradeSign() const
{
  return (this->grade_sign); 
}

int Form::getGradeExec() const
{
  return (this->grade_exec);
}

void Form::setSign(const bool sign)
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

void Form::beSigned(const Bureaucrat& bure)
{
  if (this->getSign())
    throw AlreadySignedException();
  else if (bure.getGrade() <= this->getGradeSign())
    this->sign = true;
  else
    throw GradeTooLowException();
}

/*
        ███████ ██   ██  ██████ ███████ ██████  ████████ ██  ██████  ███    ██ ███████ 
        ██       ██ ██  ██      ██      ██   ██    ██    ██ ██    ██ ████   ██ ██      
        █████     ███   ██      █████   ██████     ██    ██ ██    ██ ██ ██  ██ ███████ 
        ██       ██ ██  ██      ██      ██         ██    ██ ██    ██ ██  ██ ██      ██ 
        ███████ ██   ██  ██████ ███████ ██         ██    ██  ██████  ██   ████ ███████
*/

const char* Form::GradeTooHighException::what() const throw()
{
  return ("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
  return ("Grade is too low");
}

const char* Form::AlreadySignedException::what() const throw()
{
  return ("This form is already signed");
}


/*
          ██   ██      ██████  ██    ██ ███████ ██████  ██       ██████   █████  ██████  
         ██   ██      ██    ██ ██    ██ ██      ██   ██ ██      ██    ██ ██   ██ ██   ██ 
        ██   ██       ██    ██ ██    ██ █████   ██████  ██      ██    ██ ███████ ██   ██ 
         ██   ██      ██    ██  ██  ██  ██      ██   ██ ██      ██    ██ ██   ██ ██   ██ 
          ██   ██      ██████    ████   ███████ ██   ██ ███████  ██████  ██   ██ ██████  
*/

std::ostream& operator<<(std::ostream& out, Form& in)
{
  out << "Form: " << in.getName() << std::endl;
  out << "Grade to sign: " << in.getGradeSign() << std::endl;
  out << "Grade to execute: " << in.getGradeExec() << std::endl;
  out << "Signed: " << std::boolalpha << in.getSign() << std::noboolalpha << std::endl;
  return (out);
}