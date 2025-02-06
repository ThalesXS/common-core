/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:45:26 by txisto-d          #+#    #+#             */
/*   Updated: 2024/12/29 22:26:30 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char** argv)
{
	switch (argc)
	{
	case 1:
		std::cout << "Please write a C++ literal." << std::endl;
		break;
	case 2:
	{
		std::string cstr(argv[1]);
		ScalarConverter::convert(cstr);
		break;	
	}
	default:
		std::cout << "Please write only one C++ literal." << std::endl;;
		break;
	}
	return (0);
}