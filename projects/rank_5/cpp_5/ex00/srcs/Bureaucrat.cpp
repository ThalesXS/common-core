/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:45:45 by txisto-d          #+#    #+#             */
/*   Updated: 2024/11/22 21:50:30 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

std::ostream& operator<<(std::ostream& out, const Bureaucrat &in)
{
  out << in.getName() << ", bureaucrat grade " << in.getGrade();
  return (out);
}

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


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
  return ("Grade is too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
  return ("Grade is too low.");
}