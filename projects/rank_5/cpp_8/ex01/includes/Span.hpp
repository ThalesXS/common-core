/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:33:24 by txisto-d          #+#    #+#             */
/*   Updated: 2025/02/11 19:02:09 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <deque>
# include <exception>
# include <algorithm>
# include <utility>
# include <iostream>
# include <set>

class Span
{
	private:
		std::deque<int>	_span;
		unsigned int		_N;
	public:
		Span(unsigned int N = 0);
		Span(Span& obj);
		Span& operator=(Span& obj);
		~Span();
		
		void					addNumber(int num);
		void					addRange(std::deque<int>::const_iterator begin, std::deque<int>::const_iterator end);
		int						shortestSpan() const;
		int						longestSpan() const;
		unsigned int			max_size() const;
		void					set_max_size(unsigned int N);
		const std::deque<int>	get_span() const;
		void					printSortedUnique();

	class MaxSizeException : public std::exception
	{
		public:
			const char* what() const throw();
	};

	class EmptyException : public std::exception
	{
		public:
			const char* what() const throw();
	};

	class InvalidSizeException : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

#endif