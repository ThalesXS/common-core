/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:21:17 by txisto-d          #+#    #+#             */
/*   Updated: 2025/01/31 20:55:32 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <typename T>
void	iter(T *array, std::size_t n, void (*func_ptr)(T&))
{
	std::size_t	i = -1;

	while (++i < n)
		func_ptr(array[i]);
}

template <typename T>
void	iter(T *array, std::size_t n, void (*func_ptr)(T const &))
{
	std::size_t	i = -1;

	while (++i < n)
		func_ptr(array[i]);
}

template <typename T>
void	printMsg(T &output) 
{
	std::cout << output << std::endl;
}

#endif