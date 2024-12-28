/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:17:29 by txisto-d          #+#    #+#             */
/*   Updated: 2024/11/22 21:46:22 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include <cstdlib>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
  public:
    Form(std::string name, int grade_sign, int grade_exec);
    ~Form();
    Form(const Form& obj);
    Form& operator=(const Form& obj);

    std::string getName() const;
    bool        getSign() const;
    int         getGradeSign() const;
    int         getGradeExec() const;
    void        setSign(const bool sign);
    void        beSigned(const Bureaucrat& bure);

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

    class AlreadySignedException : public std::exception
    {
      public:
        const char* what() const throw();
    };
    
  private:
    const std::string name;
    bool              sign;
    const int         grade_sign;
    const int         grade_exec;
};

std::ostream& operator<<(std::ostream& out, Form& in);

#endif