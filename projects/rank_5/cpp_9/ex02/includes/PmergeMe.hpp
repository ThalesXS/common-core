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
# include <deque>
# include <string>
# include <sstream>
# include <ctime>
# include <cmath>
# include <exception>
# include <utility>
# include <algorithm>
# include <iomanip>

typedef std::vector<unsigned int>			t_vec;
typedef std::deque<unsigned int>			t_deque;
typedef std::vector<unsigned int>::iterator	i_vec;
typedef std::deque<unsigned int>::iterator	i_deque;

class PmergeMe
{
	private:
		t_vec	_sequence1;
		t_deque	_sequence2;
		
		void						_printVector();
		void						_printDeque();
		
		int							_jacobsthal(int k);
		void						_insertVector(t_vec& main, t_vec& pending_elements, unsigned int odd, t_vec& left, t_vec& vec, bool is_odd, int order);
		void						_mergeVector(t_vec& vec);
		void						_insertDeque(t_deque& main, t_deque& pending_elements, unsigned int odd, t_deque& left, t_deque& deque, bool is_odd, int blocks);
		void						_mergeDeque(t_deque& deque);
		bool						_onlyPositiveNumbers(char* str);
		
	public:
		PmergeMe(char** argv);
		PmergeMe(const PmergeMe& obj);
		PmergeMe& operator=(const PmergeMe& obj);
		~PmergeMe(void);
		
		void	_sortContainers(void);
		t_vec	getVector(void) const;
		t_deque	getDeque(void) const;

		class InvalidInputException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

# endif