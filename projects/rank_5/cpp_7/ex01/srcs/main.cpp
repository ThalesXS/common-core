/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:36:08 by txisto-d          #+#    #+#             */
/*   Updated: 2025/01/31 20:59:10 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	std::string strings[] = {"abacate", "banana", "cereja", "damasco", "e?"};
	float floats[] = {3.3, 2.2, 1.1, 5.5, 4.4};
	int integers[]= {1, 5, 2, 4, 3};

	std::cout<< "--- Testing iter ---" << std::endl << std::endl;

	std::cout << "string:" << std::endl;
	iter(strings, 5, printMsg<std::string>);
	std::endl(std::cout);

	std::cout << "float:" << std::endl;
	iter(floats, 5, printMsg<float>);
	std::endl(std::cout);

	std::cout << "int" << std::endl;
	iter(integers, 5, printMsg<int>);
	std::endl(std::cout);

	std::cout << "Test both iter functions (const and non-const)" << std::endl;
    int array[] = {1, 2, 3, 4, 5};
    std::size_t length = sizeof(array) / sizeof(array[0]);

    iter(array, length, printMsg<int>);

    const int constArray[] = {6, 7, 8, 9, 10};
    length = sizeof(constArray) / sizeof(constArray[0]);

	iter(constArray, length, (printMsg<const int>));
    return 0;
}