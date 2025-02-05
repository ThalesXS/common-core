/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:41:31 by txisto-d          #+#    #+#             */
/*   Updated: 2025/01/11 19:11:12 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"


bool	isDigit(const char c)
{
	if ((c >= 48 && c <= 57) || c == '-' || c == '+')
		return (true);
	return (false);
}

bool	isInt(const std::string str)
{
	const char*	cStr = str.c_str();
	int			length = str.length();
	
	for (int i = 0; i < length; i++)
	{
		if (!isDigit(cStr[i]))
			return (false);
	}
	return (true);
}

bool	isFloat(const std::string str)
{
	const char*	cStr = str.c_str();
	int			length = str.length();
	
	for (int i = 0; i < length; i++)
	{
		if (!isDigit(cStr[i]) && cStr[i] != '.' && cStr[i] != 'f')
			return (false);
		else if (cStr[i] == '.')
		{
			if (!isDigit(cStr[i + 1]))
				return (false);
		}
		else if (cStr[i] == 'f')
		{
			if (cStr[i + 1] != '\0')
				return (false);
		}
	}
	return (true);
}

bool	isDouble(const std::string str)
{
	const char*	cStr = str.c_str();
	int			length = str.length();
	
	for (int i = 0; i < length; i++)
	{
		if (!isDigit(cStr[i]) && cStr[i] != '.')
			return (false);
		else if (cStr[i] == '.')
		{
			if (!isDigit(cStr[i + 1]))
				return (false);
		}
	}
	return (true);
}

bool	isPrintNoNum(const char c)
{
	if ((c > 31 && c < 127) && (c < 48 || c > 57))
		return (true);
	return (false);
}

bool	isPseudo(const std::string str)
{
	if (str == "inf" || str == "+inf" || str == "-inf" || str == "inff" || str == "-inff" || str == "+inff" || str == "nan")
		return (true);
	return (false);
}