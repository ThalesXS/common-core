/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 09:39:27 by txisto-d          #+#    #+#             */
/*   Updated: 2024/05/20 14:32:57 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
			┏┓┏┓┳┓┏┓┏┳┓┳┓┳┳┏┓┏┳┓┏┓┳┓┏┓
			┃ ┃┃┃┃┗┓ ┃ ┣┫┃┃┃  ┃ ┃┃┣┫┗┓
			┗┛┗┛┛┗┗┛ ┻ ┛┗┗┛┗┛ ┻ ┗┛┛┗┗┛
*/

/**
 * @brief Construct a new Fixed:: Fixed object
*/
Fixed::Fixed()
{
	this->fixedNumber = 0;
}

/**
 * @brief Construct a new Fixed:: Fixed object from an int
*/
Fixed::Fixed(const int value)
{
	fixedNumber = value << this->bits;
}

/**
 * @brief Construct a new Fixed:: Fixed object from a float
*/
Fixed::Fixed(const float value)
{
	fixedNumber = value * (1 << this->bits);
}

/**
 * @brief Construct a new Fixed:: Fixed object from another Fixed object
*/
Fixed::Fixed(const Fixed &obj)
{
	fixedNumber = obj.getRawBits();
}

Fixed::~Fixed()
{
}

/*
			┳┳┓┏┓┏┳┓┓┏┏┓┳┓┏┓
			┃┃┃┣  ┃ ┣┫┃┃┃┃┗┓
			┛ ┗┗┛ ┻ ┛┗┗┛┻┛┗┛
*/

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
	return (fixedNumber);
}

/**
 * @brief Set the raw bits of a Fixed object
*/
void	Fixed::setRawBits(int const raw)
{
	fixedNumber = raw;
}


/*
	┏┓ ┏┓ ┏┓ ┳ ┏┓ ┳┓ ┳┳┓ ┏┓ ┳┓ ┏┳┓   ┏┓ ┏┓ ┏┓ ┳┓ ┏┓ ┏┳┓ ┏┓ ┳┓
	┣┫ ┗┓ ┗┓ ┃ ┃┓ ┃┃ ┃┃┃ ┣  ┃┃  ┃    ┃┃ ┃┃ ┣  ┣┫ ┣┫  ┃  ┃┃ ┣┫
	┛┗ ┗┛ ┗┛ ┻ ┗┛ ┛┗ ┛ ┗ ┗┛ ┛┗  ┻    ┗┛ ┣┛ ┗┛ ┛┗ ┛┗  ┻  ┗┛ ┛┗
*/

/**
 * @brief Assign a Fixed object to another Fixed object
*/
Fixed Fixed::operator=(const Fixed &obj)
{
	this->fixedNumber = obj.getRawBits();
	return (*this);
}

/*
		┏┓ ┓┏ ┏┓ ┳┓ ┓  ┏┓ ┏┓ ┳┓   ┏┓ ┏┓ ┏┓ ┳┓ ┏┓ ┏┳┓ ┏┓ ┳┓ ┏┓
		┃┃ ┃┃ ┣  ┣┫ ┃  ┃┃ ┣┫ ┃┃   ┃┃ ┃┃ ┣  ┣┫ ┣┫  ┃  ┃┃ ┣┫ ┗┓
		┗┛ ┗┛ ┗┛ ┛┗ ┗┛ ┗┛ ┛┗ ┻┛   ┗┛ ┣┛ ┗┛ ┛┗ ┛┗  ┻  ┗┛ ┛┗ ┗┛
*/

Fixed Fixed::operator+(const Fixed &obj)
{
	return (this->toFloat() + obj.toFloat());
}

Fixed Fixed::operator-(const Fixed &obj)
{
	return (this->toFloat() - obj.toFloat());
}

Fixed Fixed::operator*(const Fixed &obj)
{
	return (this->toFloat() * obj.toFloat());
}

Fixed Fixed::operator/(const Fixed &obj)
{
	return (this->toFloat() / obj.toFloat());
}

/*
	┏┓ ┏┓ ┳┳┓ ┏┓ ┏┓ ┳┓ ┳ ┏┓ ┳ ┏┓ ┳┓   ┏┓ ┏┓ ┏┓ ┳┓ ┏┓ ┏┳┓ ┏┓ ┳┓ ┏┓
	┃  ┃┃ ┃┃┃ ┃┃ ┣┫ ┣┫ ┃ ┗┓ ┃ ┃┃ ┃┃   ┃┃ ┃┃ ┣  ┣┫ ┣┫  ┃  ┃┃ ┣┫ ┗┓
	┗┛ ┗┛ ┛ ┗ ┣┛ ┛┗ ┛┗ ┻ ┗┛ ┻ ┗┛ ┛┗   ┗┛ ┣┛ ┗┛ ┛┗ ┛┗  ┻  ┗┛ ┛┗ ┗┛
*/

bool Fixed::operator>(const Fixed &obj) const
{
	return (this->fixedNumber > obj.getRawBits());
}

bool Fixed::operator<(const Fixed &obj) const
{
	return (this->fixedNumber < obj.getRawBits());
}

bool Fixed::operator>=(const Fixed &obj) const
{
	return (this->fixedNumber >= obj.getRawBits());
}

bool Fixed::operator<=(const Fixed &obj) const
{
	return (this->fixedNumber <= obj.getRawBits());
}

bool Fixed::operator==(const Fixed &obj) const
{
	return (this->fixedNumber == obj.getRawBits());	
}

bool Fixed::operator!=(const Fixed &obj) const
{
	return (this->fixedNumber != obj.getRawBits());	
}

/*
	┳ ┳┓ ┏┓ ┳┓ ┏┓ ┳┳┓ ┏┓ ┳┓ ┏┳┓      ┳┓ ┏┓ ┏┓ ┳┓ ┏┓ ┳┳┓ ┏┓ ┳┓ ┏┳┓
	┃ ┃┃ ┃  ┣┫ ┣  ┃┃┃ ┣  ┃┃  ┃   ━━  ┃┃ ┣  ┃  ┣┫ ┣  ┃┃┃ ┣  ┃┃  ┃ 
	┻ ┛┗ ┗┛ ┛┗ ┗┛ ┛ ┗ ┗┛ ┛┗  ┻       ┻┛ ┗┛ ┗┛ ┛┗ ┗┛ ┛ ┗ ┗┛ ┛┗  ┻
*/

Fixed Fixed::operator++(void)
{
	this->fixedNumber++;
	return (*this);
}

Fixed Fixed::operator--(void)
{
	this->fixedNumber--;
	return (*this);
}

Fixed Fixed::operator++(int empty)
{
		Fixed aux(*this);

		(void) empty;
		++(*this);
		return (aux);
}

Fixed Fixed::operator--(int empty)
{
	Fixed aux(*this);

	(void) empty;
	--(*this);
	return (aux);
}


/*
			┳┳┓ ┳ ┳┓      ┳┳┓ ┏┓ ┏┓┏┓
			┃┃┃ ┃ ┃┃  ━━  ┃┃┃ ┣┫  ┃┃ 
			┛ ┗ ┻ ┛┗      ┛ ┗ ┛┗ ┗┛┗┛
*/
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

/*
			┏┓ ┏┳┓ ┳┓ ┏┓ ┏┓ ┳┳┓   ┏┓ ┏┓ ┏┓ ┳┓ ┏┓ ┏┳┓ ┏┓ ┳┓ ┏┓
			┗┓  ┃  ┣┫ ┣  ┣┫ ┃┃┃   ┃┃ ┃┃ ┣  ┣┫ ┣┫  ┃  ┃┃ ┣┫ ┗┓
			┗┛  ┻  ┛┗ ┗┛ ┛┗ ┛ ┗   ┗┛ ┣┛ ┗┛ ┛┗ ┛┗  ┻  ┗┛ ┛┗ ┗┛
*/

/**
 * @brief Overload of the << operator to cout a Fixed object
*/
std::ostream &operator<<(std::ostream& out, const Fixed& in)
{
	out << in.toFloat();
	return (out);
}