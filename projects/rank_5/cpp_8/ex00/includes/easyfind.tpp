/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:30:36 by txisto-d          #+#    #+#             */
/*   Updated: 2025/02/09 03:28:25 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include "easyfind.hpp"

template <typename T>
int	easyfind(const T& container, int num)
{
	typename T::const_iterator position;

	position = std::find(container.begin(), container.end(), num);
	if (position == container.end())
		throw NoItemException();
	return (std::distance(container.begin(), position));
}

const char* NoItemException::what() const throw()
{
	return ("error: item not found.");
}

#endif