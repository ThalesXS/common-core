/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:07:55 by txisto-d          #+#    #+#             */
/*   Updated: 2025/02/15 14:29:33 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string expression)
{
	std::stringstream	ss;
	std::string			aux;
	
	ss.str(expression);
	try
	{
		while (getline(ss, aux, ' '))
		{
			this->_checkValue(aux);
			this->_expression.push(aux);
			if (aux == "+")
			this->_expression.push(this->_plusOperation());
			if (aux == "-")
			this->_expression.push(this->_minusOperation());
			if (aux == "*")
			this->_expression.push(this->_timesOperation());
			if (aux == "/")
			this->_expression.push(this->_divisionOperation());
		}
		if (this->_expression.size() != 1)
			throw BadInputException();
		std::cout << this->_expression.top() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	RPN::_checkValue(std::string str)
{
	std::string::iterator	begin;
	std::string::iterator	end;

	begin = str.begin();
	end = str.end();
	while (begin < end)
	{
		if (str.size() == 1)
		{
			if ((*begin < '0' || *begin > '9') && *begin != '+' && *begin != '-' && *begin != '*' && *begin != '/')
				throw BadInputException();
		}
		else
			if (*begin < '0' || *begin > '9')
				throw BadInputException();
		begin++;
	}
}

std::string	RPN::_plusOperation()
{
	std::string			num;
	std::string			base;
	std::stringstream	ss;

	this->_expression.pop();
	num = this->_expression.top();
	this->_expression.pop();
	base = this->_expression.top();
	this->_expression.pop();
	ss << atoi(base.c_str()) + atoi(num.c_str());
	return (ss.str());
}

std::string	RPN::_minusOperation()
{
	std::string			num;
	std::string			base;
	std::stringstream	ss;

	this->_expression.pop();
	num = this->_expression.top();
	this->_expression.pop();
	base = this->_expression.top();
	this->_expression.pop();
	ss << atoi(base.c_str()) - atoi(num.c_str());
	return (ss.str());
}

std::string	RPN::_timesOperation()
{
	std::string			num;
	std::string			base;
	std::stringstream	ss;

	this->_expression.pop();
	num = this->_expression.top();
	this->_expression.pop();
	base = this->_expression.top();
	this->_expression.pop();
	ss << atoi(base.c_str()) * atoi(num.c_str());
	return (ss.str());
}

std::string	RPN::_divisionOperation()
{
	std::string			num;
	std::string			base;
	std::stringstream	ss;

	this->_expression.pop();
	num = this->_expression.top();
	this->_expression.pop();
	base = this->_expression.top();
	this->_expression.pop();
	if (ator(num.c_str()) == 0)
		throw BadInputException();
	ss << atoi(base.c_str()) / atoi(num.c_str());
	return (ss.str());
}

RPN::RPN(RPN& obj) : _expression(obj.getExpression())
{
	
}

RPN& RPN::operator=(RPN& obj)
{
	this->_expression = obj.getExpression();
	return (*this);
}

RPN::~RPN()
{
	
}

std::stack<std::string>	RPN::getExpression()
{
	return (this->_expression);
}

const char*	RPN::BadInputException::what() const throw()
{
	return ("Error");
}