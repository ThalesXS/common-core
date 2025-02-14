/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:12:43 by txisto-d          #+#    #+#             */
/*   Updated: 2025/02/13 13:05:23 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Please provide a input file." << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange btc;
		btc.convertHistory(argv[1]);
	}
	catch (std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	return (0);
}