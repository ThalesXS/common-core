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

int	main(/* int argc, char** argv */)
{
	BitcoinExchange btc;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	btc.convertHistory("input.txt");
	return (0);
}