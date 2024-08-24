/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 09:39:27 by txisto-d          #+#    #+#             */
/*   Updated: 2024/08/24 08:24:04 by txisto-d         ###   ########.fr       */
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
	std::cout << "Default constructor called" << std::endl;
	this->fixedNumber = 0;
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
	fixedNumber = roundf(value * (1 << this->bits));;
}

/**
 * @brief Construct a new Fixed:: Fixed object from another Fixed object
*/
Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	fixedNumber = obj.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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
	std::cout << "Copy assingment operator called" << std::endl;
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
	return (Fixed(this->toFloat() + obj.toFloat()));
}

Fixed Fixed::operator-(const Fixed &obj)
{
	return (Fixed(this->toFloat() - obj.toFloat()));
}

Fixed Fixed::operator*(const Fixed &obj)
{
	return (Fixed(this->toFloat() * obj.toFloat()));
}

Fixed Fixed::operator/(const Fixed &obj)
{
	return (Fixed(this->toFloat() / obj.toFloat()));
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