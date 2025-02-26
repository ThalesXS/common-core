/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:52:10 by txisto-d          #+#    #+#             */
/*   Updated: 2025/01/31 20:49:20 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int	main(void)
{
	int a = 2;
	int b = 3;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "swap()\na = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "\nc = " << c << ", d = " << d << std::endl;
	swap(c, d);
	std::cout << "swap()\nc = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << max( c, d ) << std::endl;
 
	std::cout << std::endl << std::endl <<"\"My own\":" << std::endl << std::endl;

	float e = 3.3;
	float f = 2.5;
	std::cout << "\ne = " << e << ", f = " << f << std::endl;
	swap(e, f);
	std::cout << "swap()\ne = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << max( e, f ) << std::endl;
	bool g = true;
	bool h = false;
	std::cout << "\ng = " << std::boolalpha << g << ", h = " << h << std::endl;
	swap(g, h);
	std::cout << "swap()\ng = " << std::boolalpha << g << ", h = " << h << std::endl;
	std::cout << "min( g, h ) = " << min( g, h ) << std::endl;
	std::cout << "max( g, h ) = " << max( g, h ) << std::noboolalpha << std::endl;
	return 0;
}
