/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:30:36 by txisto-d          #+#    #+#             */
/*   Updated: 2025/02/05 22:30:20 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include "easyfind.hpp"

template <typename T>
T*	easyfind(const T& container, int find)
{
	T::std::iterator i;
	T::std::iterator end;
	i = T.begin();
	end = T.end();
	while (i <= end)
	{
		if (T[i] == find)
			return T;
		i++;
	}
	throw std::exception("error: item not founded");
}

#endif