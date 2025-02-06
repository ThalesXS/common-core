/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:45:45 by txisto-d          #+#    #+#             */
/*   Updated: 2024/12/28 21:35:22 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/*
         ██████   ██████ ███████ 
        ██    ██ ██      ██      
        ██    ██ ██      █████   
        ██    ██ ██      ██      
         ██████   ██████ ██    
*/

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
  if(grade < 1)
    throw GradeTooHighException();
  else if (grade > 150)
    throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name(obj.name), grade(obj.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
  this->grade = obj.grade;
  return (*this);
}

/*
         ██████  ███████ ████████     ██ ███████ ███████ ████████ 
        ██       ██         ██       ██  ██      ██         ██    
        ██   ███ █████      ██      ██   ███████ █████      ██    
        ██    ██ ██         ██     ██         ██ ██         ██    
         ██████  ███████    ██    ██     ███████ ███████    ██  
*/

std::string Bureaucrat::getName() const
{
  return (this->name);
}

int Bureaucrat::getGrade() const
{
  return (this->grade);
}

void Bureaucrat::setGrade(int val)
{
  if(grade < 1)
    throw GradeTooHighException();
  else if (grade > 150)
    throw GradeTooLowException();
  else
    this->grade = val;
}

/*
        ███    ███ ███████ ████████ ██   ██  ██████  ██████  ███████ 
        ████  ████ ██         ██    ██   ██ ██    ██ ██   ██ ██      
        ██ ████ ██ █████      ██    ███████ ██    ██ ██   ██ ███████ 
        ██  ██  ██ ██         ██    ██   ██ ██    ██ ██   ██      ██ 
        ██      ██ ███████    ██    ██   ██  ██████  ██████  ███████
*/

void Bureaucrat::incGrade()
{
  if(this->grade == 1)
    throw GradeTooHighException();
  else
  {
    this->grade--;
    std::cout << *this;
  }
}

void Bureaucrat::decGrade()
{
  if (this->grade == 150)
    throw GradeTooLowException();
  else
  {
    this->grade++;
    std::cout << *this;
  }
}


void Bureaucrat::signForm(AForm& form)
{
  try
  {
    form.beSigned(*this);
    std::cout << this->name << " signed " << form.getName() << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << this->name << " couldn't sign " << form.getName() << std::endl;
    __throw_exception_again;
  }
}

void  Bureaucrat::executeForm(AForm const & form)
{
  try
  {
	form.verifyRequirements( *this);
    std::cout << this->getName() << " executed " << form.getName() << std::endl;
  }
  catch(std::exception& e)
  {
    std::cerr << this->name << " couldn't execute " << form.getName() << std::endl;
    __throw_exception_again;
  }
}

/*
        ███████ ██   ██  ██████ ███████ ██████  ████████ ██  ██████  ███    ██ ███████ 
        ██       ██ ██  ██      ██      ██   ██    ██    ██ ██    ██ ████   ██ ██      
        █████     ███   ██      █████   ██████     ██    ██ ██    ██ ██ ██  ██ ███████ 
        ██       ██ ██  ██      ██      ██         ██    ██ ██    ██ ██  ██ ██      ██ 
        ███████ ██   ██  ██████ ███████ ██         ██    ██  ██████  ██   ████ ███████
*/

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
  return ("Grade is too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
  return ("Grade is too low.");
}

/*
          ██   ██      ██████  ██    ██ ███████ ██████  ██       ██████   █████  ██████  
         ██   ██      ██    ██ ██    ██ ██      ██   ██ ██      ██    ██ ██   ██ ██   ██ 
        ██   ██       ██    ██ ██    ██ █████   ██████  ██      ██    ██ ███████ ██   ██ 
         ██   ██      ██    ██  ██  ██  ██      ██   ██ ██      ██    ██ ██   ██ ██   ██ 
          ██   ██      ██████    ████   ███████ ██   ██ ███████  ██████  ██   ██ ██████  
*/

std::ostream& operator<<(std::ostream& out, const Bureaucrat &in)
{
  out << in.getName() << ", bureaucrat grade " << in.getGrade();
  return (out);
}