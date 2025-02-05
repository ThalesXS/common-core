/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:33:24 by txisto-d          #+#    #+#             */
/*   Updated: 2025/02/05 23:15:44 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>

class Span
{
	private:
		std::vector<int>	_span;
		unsigned int		_N;
	public:
		Span(unsigned int N = 0);
		Span(Span& obj);
		Span& operator=(Span& obj);
		~Span();
		
		void				addNumber(int num);
		int					shortestSpan() const;
		int					longestSpan() const;
		unsigned int		max_size() const;
		std::vector<int>	get_span() const;
};

#endif