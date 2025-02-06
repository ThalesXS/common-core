/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:45:50 by txisto-d          #+#    #+#             */
/*   Updated: 2024/11/22 14:06:12 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "Bureaucrat.hpp"

static void step()
{
  std::cout << "\n\nPress [Enter] to continue\n";
  std::cin.get();
  system("clear");
}

static void goodBureaucrats()
{
  try
  {
    Bureaucrat b1("Bureaucrat1", 1);
    std::cout << b1 << std::endl;
    Bureaucrat b2("Bureaucrat2", 150);
    std::cout << b2 << std::endl;
    Bureaucrat b3(b1);
    std::cout << b3 << std::endl;
    b3 = b2;
    std::cout << b3 << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }
}

static void badBureaucrats()
{
  try
  {
    Bureaucrat b1("Bureaucrat1", 0);
    std::cout << b1 << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }
  try
  {
    Bureaucrat b2("Bureaucrat2", 151);
    std::cout << b2 << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }
}

static void incDecTest()
{
  try
  {
    Bureaucrat b1("Bureaucrat1", 3);
    std::cout << b1 << std::endl;
    b1.incGrade();
    b1.incGrade();
    b1.incGrade();
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << std::endl << std::endl;
  }
  try
  {
    Bureaucrat b2("Bureaucrat2", 148);
    std::cout << b2 << std::endl;
    b2.decGrade();
    b2.decGrade();
    b2.decGrade();
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << std::endl << std::endl;
  }
}

int main(void)
{
  goodBureaucrats();
  step();
  badBureaucrats();
  step();
  incDecTest();
  return (0);
}