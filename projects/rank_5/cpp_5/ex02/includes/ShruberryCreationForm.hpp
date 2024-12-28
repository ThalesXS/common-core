/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 22:18:50 by txisto-d          #+#    #+#             */
/*   Updated: 2024/11/23 18:27:20 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP

#include "AForm.hpp"
# include "Bureaucrat.hpp"
#include <fstream>
# include <iostream>

class ShruberryCreationForm : public AForm
{
  public:
    ShruberryCreationForm(std::string target);
    ~ShruberryCreationForm();
    ShruberryCreationForm(ShruberryCreationForm& obj);
    ShruberryCreationForm& operator=(ShruberryCreationForm& obj);

    void execute(Bureaucrat const & executor) const;
    std::string getTarget() const;
    
  private:
    const std::string _target;
};

#endif