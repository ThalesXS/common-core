/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:45:50 by txisto-d          #+#    #+#             */
/*   Updated: 2024/11/23 16:20:13 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShruberryCreationForm.hpp"

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
    ShruberryCreationForm form("shruberry");
    b1.signForm(form);
    std::cout << std::endl << form << std::endl;
    b1.executeForm(form);
  }
  catch(std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }
}

static void badForms()
{
  std::cout << "To do...\n";
}

static void badSign()
{
  std::cout << "To do...\n";
}

static void twiceSign()
{
  std::cout << "To do...\n";
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