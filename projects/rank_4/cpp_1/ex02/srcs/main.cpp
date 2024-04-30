/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:43:55 by txisto-d          #+#    #+#             */
/*   Updated: 2024/04/30 21:50:35 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string		variable = "HI THIS IS BRAIN";
	std::string*	stringPTR = &variable;
	std::string&	stringREF = variable;

	std::cout << "Memory Address of \"variable\": "<< &variable << std::endl;
	std::cout << "Memory Address of \"stringPTR\": "<< stringPTR << std::endl;
	std::cout << "Memory Address of \"stringREF\": "<< &stringREF << std::endl;
	std::cout << "\n";
	std::cout << "Value of \"variable\": "<< variable << std::endl;
	std::cout << "Value of \"stringPTR\": "<< *stringPTR << std::endl;
	std::cout << "Value of \"stringREF\": "<< stringREF << std::endl;
	return (0);
}