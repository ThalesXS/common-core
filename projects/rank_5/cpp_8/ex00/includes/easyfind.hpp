/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:30:40 by txisto-d          #+#    #+#             */
/*   Updated: 2025/02/09 03:23:10 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>
# include <algorithm>

template <typename T>
int	easyfind(const T& container, int find);

class NoItemException : public std::exception
{
	public:
	const char* what() const throw();	
};

# include "easyfind.tpp"

#endif