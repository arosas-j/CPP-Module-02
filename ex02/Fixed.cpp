/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:38:56 by arosas-j          #+#    #+#             */
/*   Updated: 2024/08/24 11:40:07 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const Fixed& copy)
{
	//std::cout << "Copy constructor called" << std::endl;
	this->_value = copy.getRawBits();
}

Fixed::Fixed(const int num)
{
	//std::cout << "Int constructor called" << std::endl;
	this->_value = num << this->_fractionalBits;
}

Fixed::Fixed(const float num)
{
	//std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(num * (1 << this->_fractionalBits));
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed& copy)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (&copy != this)
		this->_value = copy.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(Fixed const& num) const
{
	Fixed result;
	result.setRawBits(this->_value + num._value);
	return (result);
}

Fixed	Fixed::operator-(Fixed const& num) const
{
	Fixed result;
	result.setRawBits(this->_value - num._value);
	return (result);
}

Fixed	Fixed::operator*(Fixed const& num) const
{
	Fixed result;
	result.setRawBits((this->_value * num._value) >> _fractionalBits);
	return (result);
}

Fixed	Fixed::operator/(Fixed const& num) const
{
	Fixed result;
	result.setRawBits((this->_value << _fractionalBits) / num._value);
	return (result);
}

bool	Fixed::operator<(Fixed const& num) const
{
	return (this->_value < num._value);
}

bool	Fixed::operator<=(Fixed const& num) const
{
	return (this->_value <= num._value);
}

bool	Fixed::operator>(Fixed const& num) const
{
	return (this->_value > num._value);
}

bool	Fixed::operator>=(Fixed const& num) const
{
	return (this->_value >= num._value);
}

bool	Fixed::operator==(Fixed const& num) const
{
	return (this->_value == num._value);
}

bool	Fixed::operator!=(Fixed const& num) const
{
	return (this->_value != num._value);
}

Fixed	&Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	this->_value++;
	return (tmp);
}

Fixed	&Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->_value--;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &num1, Fixed &num2)
{
	if (num1._value <= num2._value)
		return (num1);
	else
		return (num2);
}

const Fixed	&Fixed::min(Fixed const &num1, Fixed const &num2)
{
	if (num1._value <= num2._value)
		return (num1);
	else
		return (num2);
}

Fixed	&Fixed::max(Fixed &num1, Fixed &num2)
{
	if (num1._value >= num2._value)
		return (num1);
	else
		return (num2);
}

const Fixed	&Fixed::max(Fixed const &num1, Fixed const &num2)
{
	if (num1._value >= num2._value)
		return (num1);
	else
		return (num2);
}

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const value)
{
	this->_value = value;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (float)(1 << this->_fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->_value >> this->_fractionalBits);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}
