/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 07:57:11 by sishizaw          #+#    #+#             */
/*   Updated: 2025/05/05 07:57:17 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue) {
    std::cout << "Int constructor called" << std::endl;
    fixedPointValue = intValue << fractionalBits;
}

Fixed::Fixed(const float floatValue) {
    std::cout << "Float constructor called" << std::endl;
    fixedPointValue = roundf(floatValue * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    fixedPointValue = other.fixedPointValue;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        fixedPointValue = other.fixedPointValue;
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(fixedPointValue) / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
    return fixedPointValue >> fractionalBits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}
