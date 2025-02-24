/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:33:27 by txisto-d          #+#    #+#             */
/*   Updated: 2025/02/15 19:40:47 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cout << "Please provide a sequence of positive integers." << std::endl;
		return (0);
	}
	PmergeMe pmm(&argv[1]);
	pmm._sortContainers();
	return (0);	
}