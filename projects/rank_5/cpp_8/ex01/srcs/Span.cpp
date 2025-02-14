/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:34:01 by txisto-d          #+#    #+#             */
/*   Updated: 2025/02/11 19:10:05 by txisto-d         ###   ########.fr       */
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
		throw MaxSizeException();
}

void	Span::addRange(std::deque<int>::const_iterator begin, std::deque<int>::const_iterator end)
{
	if (this->_N < this->_span.size() + std::distance(begin, end))
		throw MaxSizeException();
	else
		this->_span.insert(this->_span.end(), begin, end);
}

int	Span::shortestSpan() const
{
	if (this->_N < 2 || !this->_span.size())
		throw EmptyException();
	std::set<int> mySet(this->_span.begin(), this->_span.end());
	if (mySet.size() != this->_span.size())
		return (0);
	std::deque<int>					copy(this->_span);
	std::deque<int>::const_iterator	begin;
	std::deque<int>::iterator		end;
	
	std::sort(copy.begin(), copy.end());
	end = std::unique(copy.begin(), copy.end());
	copy.resize(end - copy.begin());
	begin = copy.begin();
	end = copy.end() - 1;
	while (end - begin > 1)
	{
		if (*(begin + 1) - *begin < *end - *(end - 1))
			end--;
		else
			begin++;
	}
	return (*end - *begin);
	
}

int	Span::longestSpan() const
{
	std::deque<int>::const_iterator min;
	std::deque<int>::const_iterator max;
	
	if (this->_N < 2 || !this->_span.size())
		throw EmptyException();
	min = std::min_element(this->_span.begin(), this->_span.end());
	max = std::max_element(this->_span.begin(), this->_span.end());
	return ( *max - *min);
}

unsigned int	Span::max_size() const
{
	return (this->_N);
}

void	Span::set_max_size(unsigned int N)
{
	if (this->max_size() > N)
		throw InvalidSizeException();
	this->_N = N;
}

void	Span::printSortedUnique()
{
	std::deque<int>					copy(this->_span);
	std::deque<int>::const_iterator	begin;
	std::deque<int>::iterator		end;
	
	sort(copy.begin(), copy.end());
	std::cout << "Sorted values: " << std::endl;
	begin = copy.begin();
	end = copy.end();
	while (begin < end)
		std::cout << *begin++ << " ";
	std::cout << std::endl;
	end = unique(copy.begin(), copy.end());
	copy.resize(end - copy.begin());
	begin = copy.begin();
	end = copy.end();
	std::cout << "Sorted and unique values:" << std::endl;
	while (begin < end)
		std::cout << *begin++ << " ";
	std::cout << std::endl;
}

const std::deque<int>	Span::get_span() const
{
	return (this->_span);
}

const char* Span::MaxSizeException::what() const throw()
{
	return ("error: Adding the requested number(s) will surpass Span max size.");	
}

const char* Span::EmptyException::what() const throw()
{
	return ("error: Span size is not enough.");
}

const char* Span::InvalidSizeException::what() const throw()
{
	return ("error: Invalid size");
}