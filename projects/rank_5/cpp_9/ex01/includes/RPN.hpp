/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:08:03 by txisto-d          #+#    #+#             */
/*   Updated: 2025/02/15 14:26:09 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <cmath>
# include <stack>
# include <string>
# include <cstdlib>
# include <sstream>
# include <exception>

class RPN
{
    private:
        std::stack<std::string> _expression;

		std::string				_plusOperation();
		std::string				_minusOperation();
		std::string				_timesOperation();
		std::string				_divisionOperation();
		void					_checkValue(std::string str);
		
    public:
        RPN(std::string expression = "");
        RPN(RPN& obj);
        RPN& operator=(RPN& obj);
        ~RPN();
		
		std::stack<std::string>	getExpression();

		class BadInputException : public std::exception
		{
			public:
				const char* what() const throw();
		};

};

#endif