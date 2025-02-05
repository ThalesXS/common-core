/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:33:27 by txisto-d          #+#    #+#             */
/*   Updated: 2025/01/06 13:30:16 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>

bool		isDigit(const char c);
bool		isPrintNoNum(const char c);
bool		isInt(const std::string str);
bool		isFloat(const std::string str);
bool		isDouble(const std::string str);
bool		isPseudo(const std::string str);
std::string	floatToString(float floatNumber);

#endif