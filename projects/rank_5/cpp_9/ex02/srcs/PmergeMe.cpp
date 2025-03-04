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
		if (!_onlyPositiveNumbers(*argv))
			throw InvalidInputException();
		
		value = static_cast<unsigned int>(std::strtod(*argv, NULL));
		this->_sequence1.push_back(value);
		this->_sequence2.push_back(value);
		argv++;
	}
}

PmergeMe::PmergeMe(const PmergeMe& obj)
{
	this->_sequence1 = obj.getVector();
	this->_sequence2 = obj.getDeque();
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj)
{
	this->_sequence1 = obj.getVector();
	this->_sequence2 = obj.getDeque();
	return (*this);
}

PmergeMe::~PmergeMe(void)
{
	
}

void	PmergeMe::_sortContainers(void)
{
	clock_t vec[2];
	clock_t	lst[2];
	
	std::cout << "Before:\t";
	this->_printVector();
	vec[0] = clock();
	this->_mergeVector(this->_sequence1);
	vec[1] = clock();
	lst[0] = clock();
	this->_mergeDeque(this->_sequence2);
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

void	PmergeMe::_insertVector(t_vec& main, t_vec& pending_elements, unsigned int odd, t_vec& left, t_vec& vec, bool is_odd, int blocks)
{
	i_vec end;

	if (pending_elements.size() == 1)
	{
		end = std::upper_bound(main.begin(), main.end(), *pending_elements.begin());
		main.insert(end, *pending_elements.begin());
	}
	else if (pending_elements.size() > 1)
	{
		size_t jacob = 3;
		size_t count = 0;
		size_t idx;
		size_t decrease;

		while (!pending_elements.empty())
		{
			idx = this->_jacobsthal(jacob) - this->_jacobsthal(jacob - 1);
			if (idx > pending_elements.size())
				idx = pending_elements.size();
			decrease = 0;
			while (idx)
			{
				if (this->_jacobsthal(jacob + count) - decrease <= main.size())
					end = main.begin() + this->_jacobsthal(jacob + count) - decrease;
				else
					end = main.end();
				end = std::upper_bound(main.begin(), end, *(pending_elements.begin() + idx - 1));
				main.insert(end, *(pending_elements.begin() + idx - 1));
				pending_elements.erase(pending_elements.begin() + idx - 1);
				idx--;
				decrease++;
				count++;
			}
			jacob++;
		}
	}

	t_vec final;

	if (is_odd)
	{
		end = std::upper_bound(main.begin(), main.end(), odd);
		main.insert(end, odd);
	}
	for (i_vec it = main.begin(); it != main.end(); it++)
	{
		i_vec ite = std::find(vec.begin(), vec.end(), *it);
		final.insert(final.end(), ite - (blocks - 1), ite + 1);
	}
	final.insert(final.end(), left.begin(), left.end());
	vec = final;
}

void	PmergeMe::_mergeVector(t_vec& vec)
{
	static int blocks = 1;
	
	int block_size = vec.size() / blocks;
	if (block_size < 2)
		return ;
	bool is_odd = block_size % 2 == 1;
	i_vec start = vec.begin();
	i_vec end = vec.begin() + ((blocks * block_size) - (is_odd * blocks));
	for (i_vec it = start; it < end; it += (blocks * 2))
	{
		if (*(it + (blocks - 1)) > *(it + ((blocks  * 2) - 1)))
		{
			for (int i = 0; i < blocks; i++)
			{
				std::swap(*(it + i), *(it + i + blocks));
			}
		}
	}

	blocks *= 2;
	this->_mergeVector(vec);
	blocks /= 2;

	t_vec			main;
	t_vec			pending_elements;
	t_vec			left;
	unsigned int	odd = 0;
	
	main.push_back(*(start + blocks - 1));
	main.push_back(*(start + blocks * 2 - 1));
	for (i_vec it = start + blocks * 2; it < end; it += blocks)
	{
		pending_elements.push_back(*(it + blocks - 1));
		it += blocks;
		main.push_back(*(it + blocks - 1));
	}
	if (is_odd)
		odd = *(end + blocks - 1);
	left.insert(left.end(), end + (blocks * is_odd), vec.end());
	if (is_odd || !pending_elements.empty())
		this->_insertVector(main, pending_elements, odd, left, vec, is_odd, blocks);
}
		

void	PmergeMe::_insertDeque(t_deque& main, t_deque& pending_elements, unsigned int odd, t_deque& left, t_deque& deque, bool is_odd, int blocks)
{
	i_deque end;

	if (pending_elements.size() == 1)
	{
		end = std::upper_bound(main.begin(), main.end(), *pending_elements.begin());
		main.insert(end, *pending_elements.begin());
	}
	else if (pending_elements.size() > 1)
	{
		size_t jacob = 3;
		size_t count = 0;
		size_t idx;
		size_t decrease;

		while (!pending_elements.empty())
		{
			idx = this->_jacobsthal(jacob) - this->_jacobsthal(jacob - 1);
			if (idx > pending_elements.size())
				idx = pending_elements.size();
			decrease = 0;
			while (idx)
			{
				if (this->_jacobsthal(jacob + count) - decrease <= main.size())
					end = main.begin() + this->_jacobsthal(jacob + count) - decrease;
				else
					end = main.end();
				end = std::upper_bound(main.begin(), end, *(pending_elements.begin() + idx - 1));
				main.insert(end, *(pending_elements.begin() + idx - 1));
				pending_elements.erase(pending_elements.begin() + idx - 1);
				idx--;
				decrease++;
				count++;
			}
			jacob++;
		}
	}

	t_deque final;

	if (is_odd)
	{
		end = std::upper_bound(main.begin(), main.end(), odd);
		main.insert(end, odd);
	}
	for (i_deque it = main.begin(); it != main.end(); it++)
	{
		i_deque ite = std::find(deque.begin(), deque.end(), *it);
		final.insert(final.end(), ite - (blocks - 1), ite + 1);
	}
	final.insert(final.end(), left.begin(), left.end());
	deque = final;
}

void	PmergeMe::_mergeDeque(t_deque& deque)
{
	static int blocks = 1;
	
	int block_size = deque.size() / blocks;
	if (block_size < 2)
		return ;
	bool is_odd = block_size % 2;
	i_deque start = deque.begin();
	i_deque end = deque.begin() + ((blocks * block_size) - (is_odd * blocks));
	for (i_deque it = start; it < end; it += (blocks * 2))
	{
		if (*(it + (blocks - 1)) > *(it + ((blocks  * 2) - 1)))
		{
			for (int i = 0; i < blocks; i++)
			{
				std::swap(*(it + i), *(it + i + blocks));
			}
		}
	}

	blocks *= 2;
	this->_mergeDeque(deque);
	blocks /= 2;

	t_deque			main;
	t_deque			pending_elements;
	t_deque			left;
	unsigned int	odd = 0;
	
	main.push_back(*(start + blocks - 1));
	main.push_back(*(start + blocks * 2 - 1));
	for (i_deque it = start + blocks * 2; it < end; it += blocks)
	{
		pending_elements.push_back(*(it + blocks - 1));
		it += blocks;
		main.push_back(*(it + blocks - 1));
	}
	if (is_odd)
		odd = *(end + blocks - 1);
	left.insert(left.end(), end + (blocks * is_odd), deque.end());
	if (is_odd || !pending_elements.empty())
		this->_insertDeque(main, pending_elements, odd, left, deque, is_odd, blocks);
}

t_vec PmergeMe::getVector(void) const
{
	return (this->_sequence1);
}

t_deque PmergeMe::getDeque(void) const
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

void	PmergeMe::_printDeque(void)
{
	i_deque begin;
	i_deque end;
	
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

bool PmergeMe::_onlyPositiveNumbers(char* str)
{
	int	i = 0;
	
	if (str[i] == '+')
			i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9'))
			return (false);
		i++;
	}
	return (true);
}

const char* PmergeMe::InvalidInputException::what() const throw()
{
	return ("error: invalid input");
}
