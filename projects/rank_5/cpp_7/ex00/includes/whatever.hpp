/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:41:57 by txisto-d          #+#    #+#             */
/*   Updated: 2025/02/08 13:56:47 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP


template <typename T>
void swap(T& arg1, T& arg2)
{
	T temp = arg1;
	arg1 = arg2;
	arg2 = temp;
}

template <typename T>
T min(T& arg1, T& arg2)
{
	if (arg1 < arg2)
		return (arg1);
	return (arg2);
}
template <typename T>
T max(T& arg1, T& arg2)
{
	if (arg1 > arg2)
		return (arg1);
	return (arg2);
}


# endif