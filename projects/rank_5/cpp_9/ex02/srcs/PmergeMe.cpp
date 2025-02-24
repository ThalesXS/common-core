/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:33:38 by txisto-d          #+#    #+#             */
/*   Updated: 2025/02/15 19:49:10 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char** argv)
{
	unsigned int		value;
	
	while (*argv)
	{
		value = static_cast<unsigned int>(std::strtod(*argv, NULL));
		this->_sequence1.push_back(value);
		this->_sequence2.push_back(value);
		argv++;
	}
}

PmergeMe::PmergeMe(PmergeMe& obj)
{
	this->_sequence1 = obj.getVector();
	this->_sequence2 = obj.getList();
}

PmergeMe& PmergeMe::operator=(PmergeMe& obj)
{
	this->_sequence1 = obj.getVector();
	this->_sequence2 = obj.getList();
	return (*this);
}

PmergeMe::~PmergeMe(void)
{
	
}

void	PmergeMe::_sortContainers()
{
	clock_t vec[2];
	clock_t	lst[2];
	
	std::cout << "Before:\t";
	this->_printVector();
	vec[0] = clock();
	this->_mergeVector(this->_sequence1);
	vec[1] = clock();
	lst[0] = clock();
	this->_mergeList(this->_sequence2);
	lst[1] = clock();
	std::cout << "After:\t";
	this->_printVector();
	std::cout << std::fixed << std::setprecision(5) << "Time to process a range of " << this->_sequence1.size() << " elements with std::vector<unsigned int> : " << (double)(vec[1] - vec[0]) / CLOCKS_PER_SEC << " s\n";
	std::cout << "Time to process a range of " << this->_sequence2.size() << " elements with std::deque<unsigned int> : " << (double)(lst[1] - lst[0]) / CLOCKS_PER_SEC << " s\n";
}

int	PmergeMe::_jacobsthal(int k)
{
	return (round((pow(2, k+1) + pow(-1, k)) / 3));
}

void	PmergeMe::_insertVector(t_vec& main, t_vec& pend, unsigned int odd, t_vec& left, t_vec& vec, bool is_odd, int order)
{
	i_vec end;

	if (pend.size() == 1)
	{
		end = std::upper_bound(main.begin(), main.end(), *pend.begin());
		main.insert(end, *pend.begin());
	}
	else if (pend.size() > 1)
	{
		size_t jacob = 3;
		size_t count = 0;
		size_t idx;
		size_t decrease;

		while (!pend.empty())
		{
			idx = this->_jacobsthal(jacob) - this->_jacobsthal(jacob - 1);
			if (idx > pend.size())
				idx = pend.size();
			decrease = 0;
			while (idx)
			{
				end = main.begin();
				if (this->_jacobsthal(jacob + count) - decrease <= main.size())
					end = main.begin() + this->_jacobsthal(jacob + count) - decrease;
				else
					end = main.end();
				end = std::upper_bound(main.begin(), end, *(pend.begin() + idx - 1));
				main.insert(end, *(pend.begin() + idx - 1));
				pend.erase(pend.begin() + idx - 1);
				idx--;
				decrease++;
				count++;
			}
			jacob++;
		}
	}

	t_vec yaslam;

	if (is_odd)
	{
		end = std::upper_bound(main.begin(), main.end(), odd);
		main.insert(end, odd);
	}
	for (i_vec it = main.begin(); it != main.end(); it++)
	{
		i_vec ite = std::find(vec.begin(), vec.end(), *it);
		yaslam.insert(yaslam.end(), ite - (order - 1), ite + 1);
	}
	yaslam.insert(yaslam.end(), left.begin(), left.end());
	vec = yaslam;
}

void	PmergeMe::_mergeVector(t_vec& vec)
{
	static int order = 1;
	
	int unit_size = vec.size() / order;
	if (unit_size < 2)
		return ;
	bool is_odd = unit_size % 2 == 1;
	i_vec start = vec.begin();
	i_vec end = vec.begin() + ((order * unit_size) - (is_odd * order));
	for (i_vec it = start; it < end; it += (order * 2))
	{
		if (*(it + (order - 1)) > *(it + ((order  * 2) - 1)))
		{
			for (int i = 0; i < order; i++)
			{
				std::swap(*(it + i), *(it + i + order));
			}
		}
	}

	order *= 2;
	this->_mergeVector(vec);
	order /= 2;

	t_vec			main;
	t_vec			pend;
	t_vec			left;
	unsigned int	odd = 0;
	
	main.push_back(*(start + order - 1));
	main.push_back(*(start + order * 2 - 1));
	for (i_vec it = start + order * 2; it < end; it += order)
	{
		pend.push_back(*(it + order - 1));
		it += order;
		main.push_back(*(it + order - 1));
	}
	if (is_odd)
		odd = *(end + order - 1);
	left.insert(left.end(), end + (order * is_odd), vec.end());
	if (is_odd || !pend.empty())
		this->_insertVector(main, pend, odd, left, vec, is_odd, order);
}
		

void	PmergeMe::_insertList(t_list& main, t_list& pend, unsigned int odd, t_list& left, t_list& list, bool is_odd, int order)
{
	i_list end;

	if (pend.size() == 1)
	{
		end = std::upper_bound(main.begin(), main.end(), *pend.begin());
		main.insert(end, *pend.begin());
	}
	else if (pend.size() > 1)
	{
		size_t jacob = 3;
		size_t count = 0;
		size_t idx;
		size_t decrease;

		while (!pend.empty())
		{
			idx = this->_jacobsthal(jacob) - this->_jacobsthal(jacob - 1);
			if (idx > pend.size())
				idx = pend.size();
			decrease = 0;
			while (idx)
			{
				end = main.begin();
				if (this->_jacobsthal(jacob + count) - decrease <= main.size())
					end = main.begin() + this->_jacobsthal(jacob + count) - decrease;
				else
					end = main.end();
				end = std::upper_bound(main.begin(), end, *(pend.begin() + idx - 1));
				main.insert(end, *(pend.begin() + idx - 1));
				pend.erase(pend.begin() + idx - 1);
				idx--;
				decrease++;
				count++;
			}
			jacob++;
		}
	}

	t_list yaslam;

	if (is_odd)
	{
		end = std::upper_bound(main.begin(), main.end(), odd);
		main.insert(end, odd);
	}
	for (i_list it = main.begin(); it != main.end(); it++)
	{
		i_list ite = std::find(list.begin(), list.end(), *it);
		yaslam.insert(yaslam.end(), ite - (order - 1), ite + 1);
	}
	yaslam.insert(yaslam.end(), left.begin(), left.end());
	list = yaslam;
}

void	PmergeMe::_mergeList(t_list& list)
{
	static int order = 1;
	
	int unit_size = list.size() / order;
	if (unit_size < 2)
		return ;
	bool is_odd = unit_size % 2 == 1;
	i_list start = list.begin();
	i_list end = list.begin() + ((order * unit_size) - (is_odd * order));
	for (i_list it = start; it < end; it += (order * 2))
	{
		if (*(it + (order - 1)) > *(it + ((order  * 2) - 1)))
		{
			for (int i = 0; i < order; i++)
			{
				std::swap(*(it + i), *(it + i + order));
			}
		}
	}

	order *= 2;
	this->_mergeList(list);
	order /= 2;

	t_list			main;
	t_list			pend;
	t_list			left;
	unsigned int	odd = 0;
	
	main.push_back(*(start + order - 1));
	main.push_back(*(start + order * 2 - 1));
	for (i_list it = start + order * 2; it < end; it += order)
	{
		pend.push_back(*(it + order - 1));
		it += order;
		main.push_back(*(it + order - 1));
	}
	if (is_odd)
		odd = *(end + order - 1);
	left.insert(left.end(), end + (order * is_odd), list.end());
	if (is_odd || !pend.empty())
		this->_insertList(main, pend, odd, left, list, is_odd, order);
}

t_vec PmergeMe::getVector(void)
{
	return (this->_sequence1);
}

t_list PmergeMe::getList(void)
{
	return (this->_sequence2);
}

void	PmergeMe::_printVector(void)
{
	i_vec begin;
	i_vec end;
	
	begin = this->_sequence1.begin();
	end = this->_sequence1.end();
	while (begin < end)
	{
		std::cout << *begin;
		if (*(++begin))
			std::cout << " ";
	}
	std::cout << "\n";
}

void	PmergeMe::_printList(void)
{
	i_list begin;
	i_list end;
	
	begin = this->_sequence2.begin();
	end = this->_sequence2.end();
	while (begin != end)
	{
		std::cout << *begin;
		if (*(++begin))
			std::cout << " ";
	}
	std::cout << "\n";
}

const char* PmergeMe::DuplicateException::what() const throw()
{
	return ("error: duplicate values.");
}

const char* PmergeMe::NegativeException::what() const throw()
{
	return ("error: negative values.");
}
