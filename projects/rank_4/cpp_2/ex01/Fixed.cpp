/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 09:39:27 by txisto-d          #+#    #+#             */
/*   Updated: 2024/05/20 13:42:34 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * @brief Construct a new Fixed:: Fixed object
*/
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedNumber = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/**
 * @brief Construct a new Fixed:: Fixed object from another Fixed object
*/
Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	fixedNumber = obj.getRawBits();
}

/**
 * @brief Construct a new Fixed:: Fixed object from an int
*/
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	fixedNumber = value << this->bits;
}

/**
 * @brief Construct a new Fixed:: Fixed object from a float
*/
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	fixedNumber = value * (1 << this->bits);
}

/**
 * @brief Assign a Fixed object to another Fixed object
*/
Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assingment operator called" << std::endl;
	this->fixedNumber = obj.getRawBits();
	return (*this);
}

/**
 * @brief Convert a Fixed object to an int
*/
int		Fixed::toInt(void) const
{
	return (this->fixedNumber >> bits);	
}

/**
 * @brief Convert a Fixed object to a float
*/
float	Fixed::toFloat(void) const
{
	return ( (float) this->fixedNumber / (float) (1 << bits));
}

/**
 * @brief Get the raw bits of a Fixed object
*/
int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixedNumber);
}

/**
 * @brief Set the raw bits of a Fixed object
*/
void	Fixed::setRawBits(int const raw)
{
	fixedNumber = raw;
	std::cout << "setRawBits member function called" << std::endl;
}

std::ostream &operator<<(std::ostream& out, const Fixed& in)
{
	out << in.toFloat();
	return (out);
}