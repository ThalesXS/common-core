/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:17:29 by txisto-d          #+#    #+#             */
/*   Updated: 2024/12/28 21:35:09 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include <cstdlib>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
  public:
    AForm(std::string name, int grade_sign, int grade_exec);
    virtual ~AForm();
    AForm(const AForm& obj);
    AForm& operator=(const AForm& obj);

    std::string   getName() const;
    bool          getSign() const;
    int           getGradeSign() const;
    int           getGradeExec() const;
    void          setSign(const bool sign);
    void          beSigned(const Bureaucrat& bure);
    virtual void  execute(Bureaucrat const & executor) const = 0;
    void          verifyRequirements(const Bureaucrat& executor) const;

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

    class NotSignedException : public std::exception
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

std::ostream& operator<<(std::ostream& out, AForm& in);

#endif
