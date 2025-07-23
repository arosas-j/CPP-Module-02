/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:51:07 by arosas-j          #+#    #+#             */
/*   Updated: 2024/08/24 11:41:44 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;
	
	//Go crazy here
	std::cout << std::endl;
	std::cout << "Other tests:" << std::endl;

	Fixed num1(0.123456f);
	Fixed num2(4242.4242f);
	Fixed num3(654321);
	Fixed result;

	std::cout << num1 << std::endl;
	std::cout << num2 << std::endl;
	std::cout << num3 << std::endl;
	if (num1 < num2)
		std::cout << num2 << " is bigger than " << num1 << std::endl;
	else
		std::cout << num1 << " is bigger than " << num2 << std::endl;
	result = num1 * num2;
	std::cout << result << std::endl;
	std::cout << Fixed::min(result, num3) << std::endl;
	return 0;
}
