/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:37:05 by arosas-j          #+#    #+#             */
/*   Updated: 2024/08/09 15:53:57 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_fractionalBits;
	public:
		Fixed(void);
		~Fixed();
		Fixed(const Fixed& copy);
		Fixed&	operator=(Fixed const& copy);
		int		getRawBits() const;
		void	setRawBits(int const raw);
};

#endif