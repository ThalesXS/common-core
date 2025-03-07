/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:07:57 by txisto-d          #+#    #+#             */
/*   Updated: 2025/02/15 14:26:00 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Please provide a reverse polish notation." << std::endl; 
	}
	else
	{	
		RPN rpn(argv[1]);
	}
	return (0);
}