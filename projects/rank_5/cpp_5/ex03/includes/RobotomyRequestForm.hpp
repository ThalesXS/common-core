/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 22:30:44 by txisto-d          #+#    #+#             */
/*   Updated: 2024/12/28 20:35:33 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <cmath>
# include <iostream>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(std::string name);
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm& obj);
		RobotomyRequestForm& operator=(RobotomyRequestForm& obj);

		void execute(Bureaucrat const & executor) const;
		std::string getTarget() const;
		
	private:
		const std::string _target;
};

#endif