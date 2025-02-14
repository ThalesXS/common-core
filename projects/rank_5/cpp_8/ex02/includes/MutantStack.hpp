/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:38:58 by txisto-d          #+#    #+#             */
/*   Updated: 2025/02/11 22:00:07 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack<T>(void);
		MutantStack<T>(MutantStack<T>& obj);
		MutantStack& operator=(MutantStack<T>& obj);
		~MutantStack<T>(void);
		
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		
		iterator					begin();
		iterator					end();
		reverse_iterator			rbegin();
		reverse_iterator			rend();

};

# include <MutantStack.tpp>

#endif