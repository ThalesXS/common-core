/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:15:24 by txisto-d          #+#    #+#             */
/*   Updated: 2024/12/29 22:57:47 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <cstdlib>
#include <string>
#include <iomanip>

class ScalarConverter
{
	public:
		static void convert(std::string& str);

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const & obj);
		virtual ~ScalarConverter() = 0;
		ScalarConverter& operator=(ScalarConverter const & obj);

		static void convertChar(std::string const str, long double ld);
		static void convertInt(std::string const str, long double ld);
		static void convertFloat(std::string const str, long double ld);
		static void convertDouble(std::string const str, long double ld);

		static void printChar(char c, long double ld);
		static void printInt(int i, long double ld);
		static void printFloat(float f, long double ld);
		static void printDouble(double d, long double ld);

		static void printOverflow();
};

#endif