/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:10:17 by txisto-d          #+#    #+#             */
/*   Updated: 2025/02/01 20:44:56 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"
# include <iostream>

template <typename T>
Array<T>::Array() : _elements(new T[0]), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _elements(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array& obj) : _elements(new T[obj._size]), _size(obj._size)
{
	for (size_t i = 0; i < _size; ++i)
	{
		this->_elements[i] = obj[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->_elements;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& obj)
{
	if (this != &obj)
	{
		delete[] this->_elements;
		this->_size = obj.size();
		this->_elements = new T[this->_size];
		for (size_t i = 0; i < this->_size; ++i)
		{
			this->_elements[i] = obj[i];
		}
	}
	return *this;
} 

template <typename T>
T& Array<T>::operator[](size_t i)
{
	if (i >= _size)
	{
		throw SizeException();
	}
	return _elements[i];
}

template <typename T>
const T& Array<T>::operator[](size_t i) const
{
	if (i >= _size)
	{
		throw SizeException();
	}
	return _elements[i];
}

template <typename T>
std::size_t Array<T>::size() const
{
	return this->_size;
}

template <typename T>
const char* Array<T>::SizeException::what() const throw()
{
	return ("error: size out of bounds.");
}
#endif