/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:45:47 by txisto-d          #+#    #+#             */
/*   Updated: 2024/11/22 21:38:19 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include <cstdlib>

class Bureaucrat
{
  public:
    Bureaucrat(const std::string name = "Bureaucrat", int grade = 150);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& obj);
    Bureaucrat& operator=(const Bureaucrat& obj);
    
    std::string getName() const;
    int getGrade() const;
    void setGrade(int val);

    void incGrade();
    void decGrade();

    class GradeTooHighException : public std::exception
    {
      public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
      public:
        const char* what() const throw();
    };

  private:
    const std::string name;
    int               grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& in);


# endif