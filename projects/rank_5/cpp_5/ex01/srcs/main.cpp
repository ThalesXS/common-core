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

#define RED "\033[31m"
#define GREEN "\033[32m"
#define ORANGE "\033[38;5;208m"
#define PURPLE "\e[35m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

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
    std::cout << CYAN << b1 << RESET << std::endl;
    Form f1("XLR8", 1, 1);
    std::cout << GREEN << f1 << RESET << std::endl;
    Form f2("XLR9", 150, 150);
    b1.signForm(f1);
    b1.signForm(f2);
    std::cout << std::endl << GREEN << f2 << RESET << std::endl;
    f2.setSign(false);
    std::cout << GREEN << f2 << RESET << std::endl;
    f2 = f1;
    std::cout << GREEN << f2 << RESET << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }
}

static void badForms()
{
  try
  {
    Bureaucrat b1("Bureaucrat1", 1);
    Form f1("XLR8", 0, 1);
    std::cout << GREEN << f1 << RESET << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << RED << e.what() << std::endl;
  }
  try
  {
    Bureaucrat b1("Bureaucrat1", 1);
    Form f1("XLR8", 1, 0);
    std::cout << GREEN << f1 << RESET << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }
  try
  {
    Bureaucrat b2("Bureaucrat2", 150);
    Form f2("XLR8", 151, 1);
    std::cout << GREEN << f2 << RESET << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }
  try
  {
    Bureaucrat b2("Bureaucrat2", 150);
    Form f2("XLR8", 1, 151);
    std::cout << GREEN << f2 << RESET << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }
}

static void badSign()
{
  try
  {
    Bureaucrat b1("Bureaucrat1", 6);
    std::cout << CYAN  << b1 << RESET << std::endl << std::endl;
    Form f1("XLR8", 5, 5);
    std::cout << GREEN << f1 << RESET << std::endl << std::endl;
    b1.signForm(f1);
    std::cout << GREEN << std::endl << f1 << RESET << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << RED << std::endl << e.what() << RESET << std::endl;
  }
}

static void twiceSign()
{
  try
  {
    Bureaucrat b1("Bureaucrat1", 5);
    std::cout << CYAN << b1 << RESET << std::endl;
    Form f1("Contract666", 5, 5);
    std::cout << GREEN << f1 << RESET << std::endl;
    b1.signForm(f1);
    std::cout << GREEN << std::endl << f1 << RESET << std::endl;
    b1.signForm(f1);
  }
  catch(const std::exception& e)
  {
    std::cerr << RED << e.what() << std::endl;
  }
}

int main(void)
{
  std::cout << "Good Forms:" << std::endl << std::endl;
  goodForms();
  step();
  std::cout << "Bad Forms:" << std::endl << std::endl;
  badForms();
  step();
  std::cout << "Bad Sign:" << std::endl << std::endl;
  badSign();
  step();
  std::cout << "Signing twice:" << std::endl << std::endl;
  twiceSign();
  return (0);
}