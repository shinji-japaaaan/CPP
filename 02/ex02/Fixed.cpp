/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 07:00:26 by sishizaw          #+#    #+#             */
/*   Updated: 2025/06/06 07:00:28 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : rawBits(0) {}

Fixed::Fixed(const int val) {
	rawBits = val << fractionalBits;
}

Fixed::Fixed(const float val) {
	rawBits = roundf(val * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &other) {
	rawBits = other.rawBits;
}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &other) {
	if (this != &other)
		rawBits = other.rawBits;
	return *this;
}

// Comparison operators
bool Fixed::operator>(const Fixed &other) const { return rawBits > other.rawBits; }
bool Fixed::operator<(const Fixed &other) const { return rawBits < other.rawBits; }
bool Fixed::operator>=(const Fixed &other) const { return rawBits >= other.rawBits; }
bool Fixed::operator<=(const Fixed &other) const { return rawBits <= other.rawBits; }
bool Fixed::operator==(const Fixed &other) const { return rawBits == other.rawBits; }
bool Fixed::operator!=(const Fixed &other) const { return rawBits != other.rawBits; }

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

// Increment / Decrement
Fixed &Fixed::operator++() {
	rawBits++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	rawBits++;
	return temp;
}

Fixed &Fixed::operator--() {
	rawBits--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	rawBits--;
	return temp;
}

// Utility functions
int Fixed::getRawBits() const {
	return rawBits;
}

void Fixed::setRawBits(int const raw) {
	rawBits = raw;
}

float Fixed::toFloat() const {
	return (float)rawBits / (1 << fractionalBits);
}

int Fixed::toInt() const {
	return rawBits >> fractionalBits;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b ? a : b);
}

// Stream operator
std::ostream &operator<<(std::ostream &out, const Fixed &value) {
	out << value.toFloat();
	return out;
}
