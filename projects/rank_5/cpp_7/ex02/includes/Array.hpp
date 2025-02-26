/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:09:40 by txisto-d          #+#    #+#             */
/*   Updated: 2025/02/11 21:57:29 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>
# include <limits>


template <typename T>
class Array
{
	private:
		T *_elements;
		size_t _size;
		
	public:
		Array<T>(void);
		Array<T>(unsigned int n);
		Array<T>(const Array<T>& obj);
		~Array<T>(void);
		Array& operator=(const Array<T>& obj);
		T& operator[](size_t i);
		const T& operator[](long long i) const;
		std::size_t size(void) const;
		

	class SizeException : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

# include "Array.tpp"

#endif