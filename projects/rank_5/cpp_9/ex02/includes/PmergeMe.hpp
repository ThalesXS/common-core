/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:33:48 by txisto-d          #+#    #+#             */
/*   Updated: 2025/02/15 19:46:25 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <string>
# include <sstream>
# include <ctime>
# include <cmath>
# include <exception>
# include <utility>
# include <algorithm>
# include <deque>
# include <iomanip>

typedef std::vector<unsigned int>			t_vec;
typedef std::deque<unsigned int>				t_list;
typedef std::vector<unsigned int>::iterator	i_vec;
typedef std::deque<unsigned int>::iterator	i_list;

class PmergeMe
{
	private:
		t_vec	_sequence1;
		t_list	_sequence2;
		
		void						_printVector();
		void						_printList();
		
		int							_jacobsthal(int k);
		void						_insertVector(t_vec& main, t_vec& pend, unsigned int odd, t_vec& left, t_vec& vec, bool is_odd, int order);
		void						_mergeVector(t_vec& vec);
		void						_insertList(t_list& main, t_list& pend, unsigned int odd, t_list& left, t_list& list, bool is_odd, int order);
		void						_mergeList(t_list& list);
		
	public:
		PmergeMe(char** argv);
		PmergeMe(PmergeMe& obj);
		PmergeMe& operator=(PmergeMe& obj);
		~PmergeMe();
		
		void	_sortContainers();
		t_vec	getVector();
		t_list	getList();

		class DuplicateException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class NegativeException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

# endif