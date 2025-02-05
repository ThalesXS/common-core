/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:16:19 by txisto-d          #+#    #+#             */
/*   Updated: 2025/01/11 19:11:25 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "utils.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const & obj)
{
	*this = obj;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const & obj)
{
	(void)obj;
	return *this;
}

void ScalarConverter::convert(std::string& str)
{
	long double ld = std::strtold(str.c_str(), NULL);

	if (str.length() == 1 && isPrintNoNum(str.c_str()[1]))
		convertChar(str, ld);
	else if (isInt(str))
		convertInt(str, ld);
	else if (isDouble(str))
		convertDouble(str, ld);
	else if (isFloat(str) || isPseudo(str))
		convertFloat(str, ld);
	else if (str.length() > 1 && !isPseudo(str))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	
}

void ScalarConverter::convertChar(std::string const str, long double ld)
{
	char c = str.c_str()[1];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);
	
	printChar(c, ld);
	printInt(i, ld);
	printFloat(f, ld);
	printDouble(d, ld);
}
void ScalarConverter::convertInt(std::string const str, long double ld)
{
	int i = atoi(str.c_str());
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);
	
	if (ld < -std::numeric_limits<int>::max() || ld > std::numeric_limits<int>::max())
	{
		printOverflow();
		return ;
	}
	printChar(c, ld);
	printInt(i, ld);
	printFloat(f, ld);
	printDouble(d, ld);
}
void ScalarConverter::convertFloat(std::string const str, long double ld)
{
	float f = std::strtof(str.c_str(), NULL);
	char c = static_cast<char>(f);
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);0

	if (ld < -std::numeric_limits<float>::max() || ld > std::numeric_limits<float>::max())
	{
		printOverflow();
		return ;
	}
	printChar(c, ld);
	printInt(i, ld);
	printFloat(f, ld);
	printDouble(d, ld);
}
void ScalarConverter::convertDouble(std::string const str, long double ld)
{
	double d = std::strtod(str.c_str(), NULL);
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	if (ld < -std::numeric_limits<double>::max() || ld > std::numeric_limits<double>::max())
	{
		printOverflow();
		return ;
	}
	printChar(c, ld);
	printInt(i, ld);
	printFloat(f, ld);
	printDouble(d, ld);
}

void ScalarConverter::printChar(char c, long double ld)
{
	if (c > 31 && c < 127)
		std::cout << "char: " << c << std::endl;
	else if (ld >= 0 && ld <= 255)
		std::cout << "char: Not displayable"<< std::endl;
	else
		std::cout << "char: impossible"<< std::endl;
}

void ScalarConverter::printInt(int i, long double ld)
{
	if (ld >= -std::numeric_limits<int>::max() && ld <= std::numeric_limits<int>::max())
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
}

void ScalarConverter::printFloat(float f, long double ld)
{
	if (((f * f) / f != f && f < 0) || ld < -std::numeric_limits<float>::max())
		std::cout << "float: -inff" << std::endl;
	else if (((f * f) / f != f && f > 0) || ld > std::numeric_limits<float>::max())
		std::cout << "float: +inff" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double d, long double ld)
{
	if (((d * d) / d != d && d < 0) || ld < -std::numeric_limits<double>::max())
		std::cout << "double: -inf" << std::endl;
	else if (((d * d) / d != d && d > 0) || ld > std::numeric_limits<double>::max())
		std::cout << "double: +inf" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::printOverflow()
{
	std::cout << "char: overflow" << std::endl;
	std::cout << "int: overflow" << std::endl;
	std::cout << "float: overflow" << std::endl;
	std::cout << "double: overflow" << std::endl;
}

