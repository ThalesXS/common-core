/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:45:50 by txisto-d          #+#    #+#             */
/*   Updated: 2024/11/22 22:02:20 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

static void step()
{
  std::cout << "\n\nPress [Enter] to continue\n";
  std::cin.get();
  system("clear");
}

static void goodForms()
{
  try
  {
    Bureaucrat b1("Bureaucrat1", 1);
    std::cout << b1 << std::endl;
    Form f1("XLR8", 1, 1);
    std::cout << f1 << std::endl;
    Form f2("XLR9", 150, 150);
    b1.signForm(f1);
    b1.signForm(f2);
    std::cout << std::endl << f2 << std::endl;
    f2.setSign(false);
    std::cout << f2 << std::endl;
    f2 = f1;
    std::cout << f2 << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }
}

static void badForms()
{
  try
  {
    Bureaucrat b1("Bureaucrat1", 0);
    Form f1("XLR8", 0, 1);
    std::cout << f1 << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }
  try
  {
    Bureaucrat b1("Bureaucrat1", 0);
    Form f1("XLR8", 1, 0);
    std::cout << f1 << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }
  try
  {
    Bureaucrat b2("Bureaucrat2", 151);
    Form f2("XLR8", 151, 1);
    std::cout << f2 << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }
  try
  {
    Bureaucrat b2("Bureaucrat2", 151);
    Form f2("XLR8", 1, 151);
    std::cout << f2 << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }
}

static void badSign()
{
  try
  {
    Bureaucrat b1("Bureaucrat1", 6);
    std::cout << b1 << std::endl << std::endl;
    Form f1("XLR8", 5, 5);
    std::cout << f1 << std::endl << std::endl;
    b1.signForm(f1);
    std::cout << std::endl << f1 << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << std::endl << e.what() << std::endl;
  }
}

static void twiceSign()
{
  try
  {
    Bureaucrat b1("Bureaucrat1", 5);
    std::cout << b1 << std::endl;
    Form f1("Contract666", 5, 5);
    std::cout << f1 << std::endl;
    b1.signForm(f1);
    std::cout << std::endl << f1 << std::endl;
    b1.signForm(f1);
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }
}

int main(void)
{
  goodForms();
  step();
  badForms();
  step();
  badSign();
  step();
  twiceSign();
  return (0);
}