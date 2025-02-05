/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:34:01 by txisto-d          #+#    #+#             */
/*   Updated: 2025/02/05 23:29:47 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


Span::Span(unsigned int N) : _N(N)
{

}

Span::Span(Span& obj)
{
	this->_N = obj.max_size();
	this->_span = obj.get_span();
}

Span& Span::operator=(Span& obj)
{
	this->_N = obj.max_size();
	this->_span = obj.get_span();
	return (*this);
}

Span::~Span()
{

}


void	Span::addNumber(int num)
{
	if (this->_span.size() < this->_N)
		this->_span.push_back(num);
	else
		throw std::exception("error: Span max size reached.");
}

int	Span::shortestSpan() const
{
	if (!this->_N || !this->_span.size())
		throw std::exception("error: Empty Span");
	int	min;
	int	max;
	std::vector<int>::const_iterator i;
	std::vector<int>::const_iterator end;

	i = this->_span.begin();
	end = this->_span.end();
	int min = *i;
	int max = *i;
}

int	Span::longestSpan() const
{
	if (!this->_N || !this->_span.size())
		throw std::exception("error: Empty Span");
	int	min;
	int	max;
	std::vector<int>::const_iterator i;
	std::vector<int>::const_iterator end;

	i = this->_span.begin();
	end = this->_span.end();
	int min = *i;
	int max = *i;
	while 
}

unsigned int	Span::max_size() const
{
	return (this->_N);
}

std::vector<int>	Span::get_span() const
{
	return (this->_span);
}