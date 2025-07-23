/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:37:05 by arosas-j          #+#    #+#             */
/*   Updated: 2024/08/15 18:20:20 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_value;
		static const int	_fractionalBits;
	public:
		//Constructors and destructor
		Fixed(void);
		Fixed(const Fixed& copy);
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();

		//Basic operators
		Fixed&	operator=(Fixed const& copy);
		Fixed	operator+(Fixed const& num) const;
		Fixed	operator-(Fixed const& num) const;
		Fixed	operator*(Fixed const& num) const;
		Fixed	operator/(Fixed const& num) const;

		//Comparason operators
		bool	operator<(Fixed const& num) const;
		bool	operator>(Fixed const& num) const;
		bool	operator<=(Fixed const& num) const;
		bool	operator>=(Fixed const& num) const;
		bool	operator==(Fixed const& num) const;
		bool	operator!=(Fixed const& num) const;

		//Increment and decrement
		Fixed	&operator++(void);
		Fixed	operator++(int num);
		Fixed	&operator--(void);
		Fixed	operator--(int num);

		//Other functions
		static Fixed 		&min(Fixed &num1, Fixed &num2);
		static const Fixed	&min(Fixed const &num1, Fixed const &num2);
		static Fixed		&max(Fixed &num1, Fixed &num2);
		static const Fixed	&max(Fixed const &num1, Fixed const &num2);
		int					getRawBits() const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

#endif